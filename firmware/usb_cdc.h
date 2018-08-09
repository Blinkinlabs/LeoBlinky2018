#ifndef USB_CDC_H
#define USB_CDC_H

#include <ch554_usb.h>
#include <stdint.h>

extern void USBDeviceCfg();
extern void USBDeviceIntCfg();
extern void USBDeviceEndPointCfg();

extern void DeviceInterrupt(void) __interrupt (INT_NO_USB);


extern uint8_t UsbConfig;


extern volatile __idata uint8_t USBByteCount;
extern volatile __idata uint8_t USBBufOutPoint;
extern volatile __idata uint8_t UpPoint2_Busy;


__xdata __at (0x0000) uint8_t  Ep0Buffer[DEFAULT_ENDP0_SIZE];       //Endpoint 0 OUT&IN buffer, must be an even address
__xdata __at (0x0040) uint8_t  Ep1Buffer[DEFAULT_ENDP1_SIZE];       //Endpoint 1 upload buffer
__xdata __at (0x0080) uint8_t  Ep2Buffer[2*MAX_PACKET_SIZE];        //Endpoint 2 IN & OUT buffer, must be an even address


#endif // USB_CDC_H
