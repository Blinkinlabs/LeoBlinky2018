#include <stdint.h>
#include <string.h>

#include <ch554.h>
#include <debug.h>

#include "usb_cdc.h"
#include "uart.h"

uint16_t SetupLen;
uint8_t SetupReq;
uint8_t Count;
uint8_t UsbConfig;

const uint8_t *  pDescr;                                                       //USB configuration flag
USB_SETUP_REQ   SetupReqBuf;                                                   //Staging the Setup package
#define UsbSetupBuf     ((PUSB_SETUP_REQ)Ep0Buffer)

#define  SET_LINE_CODING                0X20            // Configures DTE rate, stop-bits, parity, and number-of-character
#define  GET_LINE_CODING                0X21            // This request allows the host to find out the currently configured line coding.
#define  SET_CONTROL_LINE_STATE         0X22            // This request generates RS-232/V.24 style control signals.


//cdc parameter
__xdata uint8_t LineCoding[7]={0x00,0xe1,0x00,0x00,0x00,0x00,0x08};   // Initial baud rate is 57600, 1 stop bit, no parity, 8 data bits.


volatile __idata uint8_t USBByteCount = 0;      //Data received on behalf of the USB endpoint
volatile __idata uint8_t USBBufOutPoint = 0;    //Data pointer
volatile __idata uint8_t UpPoint2_Busy  = 0;   //Upload endpoint is busy flag




//Device descriptor
__code uint8_t DevDesc[] = {0x12,0x01,0x10,0x01,0x02,0x00,0x00,DEFAULT_ENDP0_SIZE,
                            0x86,0x1a,                        // VID: "QinHeng Electronics"
                            0x88,0x88,                        // PID: imaginary!
                            0x00,0x01,0x01,0x02,
                            0x03,0x01
                           };
__code uint8_t CfgDesc[] ={
    0x09,0x02,0x43,0x00,0x02,0x01,0x00,0xa0,0x32,             //Configuration descriptor (two interfaces)
    //The following is the interface 0 (CDC interface) descriptor
    0x09,0x04,0x00,0x00,0x01,0x02,0x02,0x01,0x00,             //CDC interface descriptor (one endpoint)
    //The following is the function descriptor
    0x05,0x24,0x00,0x10,0x01,                                 //Function descriptor (header)
    0x05,0x24,0x01,0x00,0x00,                                 //Management descriptor (no data class interface) 03 01
    0x04,0x24,0x02,0x02,                                      //Supports Set_Line_Coding、Set_Control_Line_State、Get_Line_Coding、Serial_State
    0x05,0x24,0x06,0x00,0x01,                                 //CDC interface numbered 0; data class interface number 1
    0x07,0x05,0x81,0x03,0x08,0x00,0xFF,                       //Interrupt upload endpoint descriptor
    //The following is the interface 1 (data interface) descriptor
    0x09,0x04,0x01,0x00,0x02,0x0a,0x00,0x00,0x00,             //Data interface descriptor
    0x07,0x05,0x02,0x02,0x40,0x00,0x00,                       //Endpoint descriptor
    0x07,0x05,0x82,0x02,0x40,0x00,0x00,                       //Endpoint descriptor
};

//String descriptor
unsigned char  __code LangDes[]={0x04,0x03,0x09,0x04};           //Language descriptor

////Serial number string descriptor
//unsigned char  __code SerDes[]={
//    0x14,0x03,
//    0x32,0x00,0x30,0x00,0x31,0x00,0x37,0x00,0x2D,0x00,
//    0x32,0x00,0x2D,0x00,
//    0x32,0x00,0x35,0x00
//};

// For storing an ASCII representation of the serial number
unsigned char __xdata SerDes_ID[2+12*2+8];

//Product string descriptor
unsigned char  __code Prod_Des[]={
    28,0x03,
    'L',0x00,'e',0x00,'o',0x00,'B',0x00,'l',0x00,'i',0x00,'n',0x00,'k',0x00,'y',0x00,'2',0x00,'0',0x00,'1',0x00,'8',0x00

//    0x14,0x03,
//    0x43,0x00,0x48,0x00,0x35,0x00,0x35,0x00,0x34,0x00,0x5F,0x00,
//    0x43,0x00,0x44,0x00,0x43,0x00,
};

unsigned char  __code Manuf_Des[]={
    24,0x03,
    'B',0x00,'l',0x00,'i',0x00,'n',0x00,'k',0x00,'i',0x00,'n',0x00,'l',0x00,'a',0x00,'b',0x00,'s',0x00

//    0x0A,0x03,
//    0x5F,0x6c,0xCF,0x82,0x81,0x6c,0x52,0x60,
};



/*******************************************************************************
* Function Name  : USBDeviceCfg()
* Description    : USB device mode configuration
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USBDeviceCfg()
{
    USB_CTRL = 0x00;                                                            //Clear USB control register
    USB_CTRL &= ~bUC_HOST_MODE;                                                 //Choose device mode
    USB_CTRL |=  bUC_DEV_PU_EN | bUC_INT_BUSY | bUC_DMA_EN;                     //USB device and internal pull-up enable, automatically return to NAK before interrupt flag is cleared during interrupt
    USB_DEV_AD = 0x00;                                                          //Device address initialization
    //     USB_CTRL |= bUC_LOW_SPEED;
    //     UDEV_CTRL |= bUD_LOW_SPEED;                                          //Choose low speed 1.5M mode
    USB_CTRL &= ~bUC_LOW_SPEED;
    UDEV_CTRL &= ~bUD_LOW_SPEED;                                                //Select full speed 12M mode, the default mode
    UDEV_CTRL = bUD_PD_DIS;                                                     // Disable DP/DM pull-down resistor
    UDEV_CTRL |= bUD_PORT_EN;                                                   //Enable physical port
}

/*******************************************************************************
* Function Name  : USBDeviceIntCfg()
* Description    : USB device mode interrupt initialization
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USBDeviceIntCfg()
{
    USB_INT_EN |= bUIE_SUSPEND;                                                 //Enable device hang interrupt
    USB_INT_EN |= bUIE_TRANSFER;                                                //Enable USB transfer completion interrupt
    USB_INT_EN |= bUIE_BUS_RST;                                                 //Enable device mode USB bus reset interrupt
    USB_INT_FG |= 0x1F;                                                         //Clear interrupt flag
    IE_USB = 1;                                                                 //Enable USB interrupt
    EA = 1;                                                                     //Enable interrupts
}

/*******************************************************************************
* Function Name  : USBDeviceEndPointCfg()
* Description    : Device mode endpoint configuration, emulation compatible HID device, in addition to endpoint 0 control transmission, also includes endpoint 2 batch upload and export
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USBDeviceEndPointCfg()
{
    // TODO: Is casting the right thing here? What about endianness?
    UEP1_DMA = (uint16_t) Ep1Buffer;                                            //Endpoint 1 sends the data transfer address
    UEP2_DMA = (uint16_t) Ep2Buffer;                                            //Endpoint 2 IN data transfer address
    UEP2_3_MOD = 0xCC;                                                          //Endpoint 2/3 Single Buffer Transceiver Enable
    UEP2_CTRL = bUEP_AUTO_TOG | UEP_T_RES_NAK | UEP_R_RES_ACK;                  //Endpoint 2 automatically flips the sync flag, IN transaction returns NAK, OUT returns ACK

    UEP1_CTRL = bUEP_AUTO_TOG | UEP_T_RES_NAK;                                  //Endpoint 1 automatically flips the sync flag, and the IN transaction returns NAK.
    UEP0_DMA = (uint16_t) Ep0Buffer;                                            //Endpoint 0 data transfer address
    UEP4_1_MOD = 0X40;                                                          //Endpoint 1 upload buffer; endpoint 0 single 64 byte send and receive buffer
    UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;                                  //Manual flip, OUT transaction returns ACK, IN transaction returns NAK
}

/*******************************************************************************
* Function Name  : DeviceInterrupt()
* Description    : CH559USB Interrupt handler
*******************************************************************************/
void DeviceInterrupt(void) __interrupt (INT_NO_USB)                             //USB interrupt service routine, using register set 1
{
    uint16_t len;
    if(UIF_TRANSFER)                                                            //USB transfer completion flag
    {
        switch (USB_INT_ST & (MASK_UIS_TOKEN | MASK_UIS_ENDP))
        {
        case UIS_TOKEN_IN | 1:                                                  //endpoint 1# Endpoint interrupt upload
            UEP1_T_LEN = 0;
            UEP1_CTRL = UEP1_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_NAK;           //Default response NAK
            break;
        case UIS_TOKEN_IN | 2:                                                  //endpoint 2# Endpoint bulk upload
        {
            UEP2_T_LEN = 0;                                                     //Pre-use send length must be cleared
            UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_NAK;           //Default response NAK
            UpPoint2_Busy = 0;                                                  //Clear busy flag
        }
            break;
        case UIS_TOKEN_OUT | 2:                                                 //endpoint 3# Endpoint batch download
            if ( U_TOG_OK )                                                     // Out of sync packets will be dropped
            {
                USBByteCount = USB_RX_LEN;
                USBBufOutPoint = 0;                                             //Take data pointer reset
                UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_R_RES | UEP_R_RES_NAK;       //Receive a packet of data on the NAK, the main function is processed, the main function to modify the response
            }
            break;
        case UIS_TOKEN_SETUP | 0:                                               //SETUP transaction
            len = USB_RX_LEN;
            if(len == (sizeof(USB_SETUP_REQ)))
            {
                SetupLen = ((uint16_t)UsbSetupBuf->wLengthH<<8) | (UsbSetupBuf->wLengthL);
                len = 0;                                                      //The default is success and upload 0 length
                SetupReq = UsbSetupBuf->bRequest;
                if ( ( UsbSetupBuf->bRequestType & USB_REQ_TYP_MASK ) != USB_REQ_TYP_STANDARD )//Non-standard request
                {
                    switch( SetupReq )
                    {
                    case GET_LINE_CODING:   //0x21  currently configured
                        pDescr = LineCoding;
                        len = sizeof(LineCoding);
                        len = SetupLen >= DEFAULT_ENDP0_SIZE ? DEFAULT_ENDP0_SIZE : SetupLen;  //This transmission length
                        memcpy(Ep0Buffer,pDescr,len);
                        SetupLen -= len;
                        pDescr += len;
                        break;
                    case SET_CONTROL_LINE_STATE:  //0x22  generates RS-232/V.24 style control signals
                        break;
                    case SET_LINE_CODING:      //0x20  Configure
                        break;
                    default:
                        len = 0xFF;  								 					                 /*命令不支持*/
                        break;
                    }
                }
                else                                                             //Standard request
                {
                    switch(SetupReq)                                             //Request code
                    {
                    case USB_GET_DESCRIPTOR:
                        switch(UsbSetupBuf->wValueH)
                        {
                        case 1:                                                       //Device descriptor
                            pDescr = DevDesc;                                         //Send the device descriptor to the buffer to be sent
                            len = sizeof(DevDesc);
                            break;
                        case 2:                                                        //Configuration descriptor
                            pDescr = CfgDesc;                                          //Send the device descriptor to the buffer to be sent
                            len = sizeof(CfgDesc);
                            break;
                        case 3:
                            if(UsbSetupBuf->wValueL == 0)
                            {
                                pDescr = LangDes;
                                len = sizeof(LangDes);
                            }
                            else if(UsbSetupBuf->wValueL == 1)
                            {
                                pDescr = Manuf_Des;
                                len = sizeof(Manuf_Des);
                            }
                            else if(UsbSetupBuf->wValueL == 2)
                            {
                                pDescr = Prod_Des;
                                len = sizeof(Prod_Des);
                            }
                            else
                            {
//                                pDescr = SerDes;
//                                len = sizeof(SerDes);
                                pDescr = SerDes_ID;
                                len = sizeof(SerDes_ID);
                            }
                            break;
                        default:
                            len = 0xff;                                                 //Unsupported command or error
                            break;
                        }
                        if ( SetupLen > len )
                        {
                            SetupLen = len;                                             //Limit total length
                        }
                        len = SetupLen >= DEFAULT_ENDP0_SIZE ? DEFAULT_ENDP0_SIZE : SetupLen;                            //This transmission length
                        memcpy(Ep0Buffer,pDescr,len);                                  //Load upload data
                        SetupLen -= len;
                        pDescr += len;
                        break;
                    case USB_SET_ADDRESS:
                        SetupLen = UsbSetupBuf->wValueL;                              //Scratch USB device address
                        break;
                    case USB_GET_CONFIGURATION:
                        Ep0Buffer[0] = UsbConfig;
                        if ( SetupLen >= 1 )
                        {
                            len = 1;
                        }
                        break;
                    case USB_SET_CONFIGURATION:
                        UsbConfig = UsbSetupBuf->wValueL;
                        break;
                    case USB_GET_INTERFACE:
                        break;
                    case USB_CLEAR_FEATURE:                                            //Clear Feature
                        if( ( UsbSetupBuf->bRequestType & 0x1F ) == USB_REQ_RECIP_DEVICE )                  //Clear device
                        {
                            if( ( ( ( uint16_t )UsbSetupBuf->wValueH << 8 ) | UsbSetupBuf->wValueL ) == 0x01 )
                            {
                                if( CfgDesc[ 7 ] & 0x20 )
                                {
                                    //Wake
                                }
                                else
                                {
                                    len = 0xFF;                                        //operation failed
                                }
                            }
                            else
                            {
                                len = 0xFF;                                            //operation failed
                            }
                        }
                        else if ( ( UsbSetupBuf->bRequestType & USB_REQ_RECIP_MASK ) == USB_REQ_RECIP_ENDP )// End point
                        {
                            switch( UsbSetupBuf->wIndexL )
                            {
                            case 0x83:
                                UEP3_CTRL = UEP3_CTRL & ~ ( bUEP_T_TOG | MASK_UEP_T_RES ) | UEP_T_RES_NAK;
                                break;
                            case 0x03:
                                UEP3_CTRL = UEP3_CTRL & ~ ( bUEP_R_TOG | MASK_UEP_R_RES ) | UEP_R_RES_ACK;
                                break;
                            case 0x82:
                                UEP2_CTRL = UEP2_CTRL & ~ ( bUEP_T_TOG | MASK_UEP_T_RES ) | UEP_T_RES_NAK;
                                break;
                            case 0x02:
                                UEP2_CTRL = UEP2_CTRL & ~ ( bUEP_R_TOG | MASK_UEP_R_RES ) | UEP_R_RES_ACK;
                                break;
                            case 0x81:
                                UEP1_CTRL = UEP1_CTRL & ~ ( bUEP_T_TOG | MASK_UEP_T_RES ) | UEP_T_RES_NAK;
                                break;
                            case 0x01:
                                UEP1_CTRL = UEP1_CTRL & ~ ( bUEP_R_TOG | MASK_UEP_R_RES ) | UEP_R_RES_ACK;
                                break;
                            default:
                                len = 0xFF;                                         // Unsupported endpoint
                                break;
                            }
                        }
                        else
                        {
                            len = 0xFF;                                                // Not endpoints are not supported
                        }
                        break;
                    case USB_SET_FEATURE:                                          //Set Feature
                        if( ( UsbSetupBuf->bRequestType & 0x1F ) == USB_REQ_RECIP_DEVICE )                  // Setting up the device
                        {
                            if( ( ( ( uint16_t )UsbSetupBuf->wValueH << 8 ) | UsbSetupBuf->wValueL ) == 0x01 )
                            {
                                if( CfgDesc[ 7 ] & 0x20 )
                                {
                                    //Sleep
#ifdef DE_PRINTF
                                    printf( "suspend\n" );                                                             //Sleep state
#endif
                                    while ( XBUS_AUX & bUART0_TX )
                                    {
                                        ;    //Waiting for transmission to complete
                                    }
                                    SAFE_MOD = 0x55;
                                    SAFE_MOD = 0xAA;
                                    WAKE_CTRL = bWAK_BY_USB | bWAK_RXD0_LO | bWAK_RXD1_LO;                      //USB or RXD0/1 can be woken up when there is a signal
                                    PCON |= PD;                                                                 //Sleep
                                    SAFE_MOD = 0x55;
                                    SAFE_MOD = 0xAA;
                                    WAKE_CTRL = 0x00;
                                }
                                else
                                {
                                    len = 0xFF;                                        //operation failed
                                }
                            }
                            else
                            {
                                len = 0xFF;                                            //operation failed
                            }
                        }
                        else if( ( UsbSetupBuf->bRequestType & 0x1F ) == USB_REQ_RECIP_ENDP )   //Set endpoint
                        {
                            if( ( ( ( uint16_t )UsbSetupBuf->wValueH << 8 ) | UsbSetupBuf->wValueL ) == 0x00 )
                            {
                                switch( ( ( uint16_t )UsbSetupBuf->wIndexH << 8 ) | UsbSetupBuf->wIndexL )
                                {
                                case 0x83:
                                    UEP3_CTRL = UEP3_CTRL & (~bUEP_T_TOG) | UEP_T_RES_STALL;    //Set endpoint 3 IN STALL
                                    break;
                                case 0x03:
                                    UEP3_CTRL = UEP3_CTRL & (~bUEP_R_TOG) | UEP_R_RES_STALL;    //Set endpoint 3 OUT Stall
                                    break;
                                case 0x82:
                                    UEP2_CTRL = UEP2_CTRL & (~bUEP_T_TOG) | UEP_T_RES_STALL;    //Set endpoint 2 IN STALL
                                    break;
                                case 0x02:
                                    UEP2_CTRL = UEP2_CTRL & (~bUEP_R_TOG) | UEP_R_RES_STALL;    //Set Endpoint 2 OUT Stall
                                    break;
                                case 0x81:
                                    UEP1_CTRL = UEP1_CTRL & (~bUEP_T_TOG) | UEP_T_RES_STALL;    //Set endpoint 1 IN STALL
                                    break;
                                case 0x01:
                                    UEP1_CTRL = UEP1_CTRL & (~bUEP_R_TOG) | UEP_R_RES_STALL;    //Set endpoint 1 OUT Stall
                                default:
                                    len = 0xFF;                                    //operation failed
                                    break;
                                }
                            }
                            else
                            {
                                len = 0xFF;                                      //operation failed
                            }
                        }
                        else
                        {
                            len = 0xFF;                                          //operation failed
                        }
                        break;
                    case USB_GET_STATUS:
                        Ep0Buffer[0] = 0x00;
                        Ep0Buffer[1] = 0x00;
                        if ( SetupLen >= 2 )
                        {
                            len = 2;
                        }
                        else
                        {
                            len = SetupLen;
                        }
                        break;
                    default:
                        len = 0xff;                                                    //operation failed
                        break;
                    }
                }
            }
            else
            {
                len = 0xff;                                                         //Wrong packet length
            }
            if(len == 0xff)
            {
                SetupReq = 0xFF;
                UEP0_CTRL = bUEP_R_TOG | bUEP_T_TOG | UEP_R_RES_STALL | UEP_T_RES_STALL;//STALL
            }
            else if(len <= DEFAULT_ENDP0_SIZE)                                  //Upload data or status stage returns 0 length package
            {
                UEP0_T_LEN = len;
                UEP0_CTRL = bUEP_R_TOG | bUEP_T_TOG | UEP_R_RES_ACK | UEP_T_RES_ACK;    //The default packet is DATA1, which returns a response ACK.
            }
            else
            {
                UEP0_T_LEN = 0;                                                 //Although it has not yet reached the status stage, it uploads a 0-length packet in advance to prevent the host from entering the status stage in advance.
                UEP0_CTRL = bUEP_R_TOG | bUEP_T_TOG | UEP_R_RES_ACK | UEP_T_RES_ACK;    //The default packet is DATA1, which returns a response ACK.
            }
            break;
        case UIS_TOKEN_IN | 0:                                                  //endpoint0 IN
            switch(SetupReq)
            {
            case USB_GET_DESCRIPTOR:
                len = SetupLen >= DEFAULT_ENDP0_SIZE ? DEFAULT_ENDP0_SIZE : SetupLen;       //This transmission length
                memcpy( Ep0Buffer, pDescr, len );                               //Load upload data
                SetupLen -= len;
                pDescr += len;
                UEP0_T_LEN = len;
                UEP0_CTRL ^= bUEP_T_TOG;                                        //Sync flag bit flip
                break;
            case USB_SET_ADDRESS:
                USB_DEV_AD = USB_DEV_AD & bUDA_GP_BIT | SetupLen;
                UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
                break;
            default:
                UEP0_T_LEN = 0;                                                 //The status phase completes the interrupt or is forced to upload 0 length packet end control transmission
                UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
                break;
            }
            break;
        case UIS_TOKEN_OUT | 0:  // endpoint0 OUT
            if(SetupReq ==SET_LINE_CODING)  //Set the serial port properties
            {
                if( U_TOG_OK )
                {
                    memcpy(LineCoding,UsbSetupBuf,USB_RX_LEN);
                    Config_Uart1(LineCoding);
                    UEP0_T_LEN = 0;
                    UEP0_CTRL |= UEP_R_RES_ACK | UEP_T_RES_ACK;  //Ready to upload 0 packages
                }
            }
            else
            {
                UEP0_T_LEN = 0;
                UEP0_CTRL |= UEP_R_RES_ACK | UEP_T_RES_NAK;  //State stage, responding to IN NAK
            }
            break;



        default:
            break;
        }
        UIF_TRANSFER = 0;                                                       //Write 0 to clear interrupt
    }
    if(UIF_BUS_RST)                                                             //Device Mode USB Bus Reset Interrupt
    {
#ifdef DE_PRINTF
        printf( "reset\n" );                                                             //Sleep state
#endif
        UEP0_CTRL = UEP_R_RES_ACK | UEP_T_RES_NAK;
        UEP1_CTRL = bUEP_AUTO_TOG | UEP_T_RES_NAK;
        UEP2_CTRL = bUEP_AUTO_TOG | UEP_T_RES_NAK | UEP_R_RES_ACK;
        USB_DEV_AD = 0x00;
        UIF_SUSPEND = 0;
        UIF_TRANSFER = 0;
        UIF_BUS_RST = 0;                                                                //Clear interrupt flag
        Reset_Uart1();
        USBByteCount = 0;       //Length received by the USB endpoint
        UsbConfig = 0;          //Clear configuration value
        UpPoint2_Busy = 0;
    }
    if (UIF_SUSPEND)                                                            //USB bus suspend/wake up
    {
        UIF_SUSPEND = 0;
        if ( USB_MIS_ST & bUMS_SUSPEND )                                             //Hang
        {
#ifdef DE_PRINTF
            printf( "suspend\n" );                                                             //Sleep state
#endif
            while ( XBUS_AUX & bUART0_TX )
            {
                ;    //Waiting for transmission to complete
            }
            SAFE_MOD = 0x55;
            SAFE_MOD = 0xAA;
            WAKE_CTRL = bWAK_BY_USB | bWAK_RXD0_LO | bWAK_RXD1_LO;                      //USB or RXD0/1 can be woken up when there is a signal
            PCON |= PD;                                                                 //Sleep
            SAFE_MOD = 0x55;
            SAFE_MOD = 0xAA;
            WAKE_CTRL = 0x00;
        }
    }
    else {                                                                      //Unexpected interruption, impossible situation
        USB_INT_FG = 0xFF;                                                      //Clear interrupt flag

    }
}

__code char nibbleToHex[16] =
{
    '0', '1', '2', '3', '4',
    '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E',
    'F'
};

void buildSerialId() {
    uint8_t i;
    uint8_t value;

    SerDes_ID[0] = sizeof(SerDes_ID);      // String length
    SerDes_ID[1] = 3;                      // String type

    // TODO: 3FFB should not be used?
    for(i = 0; i < 6; i++) {
        value = *((__code uint8_t *)(0x3FFA + i));
        SerDes_ID[2+i*4+0] = nibbleToHex[(value>>4) & 0x0F]; // top nibble
        SerDes_ID[2+i*4+1] = 0;
        SerDes_ID[2+i*4+2] = nibbleToHex[(value>>0) & 0x0F]; // bottom nibble
        SerDes_ID[2+i*4+3] = 0;
    }
    SerDes_ID[26] = '-';
    SerDes_ID[27] = 0x00;

#if defined(VARIANT_DIS)
    SerDes_ID[28] = 'D';
    SerDes_ID[29] = 0x00;
    SerDes_ID[30] = 'I';
    SerDes_ID[31] = 0x00;
    SerDes_ID[32] = 'S';
    SerDes_ID[33] = 0x00;
#elif defined(VARIANT_ORI)
    SerDes_ID[28] = 'O';
    SerDes_ID[29] = 0x00;
    SerDes_ID[30] = 'R';
    SerDes_ID[31] = 0x00;
    SerDes_ID[32] = 'I';
    SerDes_ID[33] = 0x00;
#elif defined(VARIANT_ENT)
    SerDes_ID[28] = 'E';
    SerDes_ID[29] = 0x00;
    SerDes_ID[30] = 'N';
    SerDes_ID[31] = 0x00;
    SerDes_ID[32] = 'T';
    SerDes_ID[33] = 0x00;
#endif
}

void USBSetup()
{
    USBDeviceCfg();
    USBDeviceEndPointCfg();                                               //Endpoint configuration
    USBDeviceIntCfg();                                                    //Interrupt initialization
    UEP0_T_LEN = 0;
    UEP1_T_LEN = 0;                                                       //Pre-use send length must be cleared
    UEP2_T_LEN = 0;                                                       //Pre-use send length must be cleared

    buildSerialId();
}
