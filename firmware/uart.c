#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <ch554.h>
#include <debug.h>

#include "uart.h"

#if 0
__idata uint8_t Receive_Uart_Buf[UART_REV_LEN];   //Serial receive buffer
volatile __idata uint8_t Uart_Input_Point = 0;   //The circular buffer write pointer, the bus reset needs to be initialized to 0
volatile __idata uint8_t Uart_Output_Point = 0;  //The circular buffer fetches the pointer, and the bus reset needs to be initialized to 0.
volatile __idata uint8_t UartByteCount = 0;      //Current buffer remaining bytes to be fetched

/*******************************************************************************
* Function Name  : Config_Uart1(uint8_t *cfg_uart)
* Description    : Configure serial port 1 parameters
* Input          : Serial port configuration parameters Four-bit baud rate, stop bit, checksum, data bit
* Output         : None
* Return         : None
*******************************************************************************/
void Config_Uart1(uint8_t *cfg_uart)
{
    uint32_t uart1_buad = 0;
    *((uint8_t *)&uart1_buad) = cfg_uart[0];
    *((uint8_t *)&uart1_buad+1) = cfg_uart[1];
    *((uint8_t *)&uart1_buad+2) = cfg_uart[2];
    *((uint8_t *)&uart1_buad+3) = cfg_uart[3];
    SBAUD1 = 256 - FREQ_SYS/16/uart1_buad; //  SBAUD1 = 256 - Fsys / 16 / baud rate
    IE_UART1 = 1;
}

/*******************************************************************************
* Function Name  : Uart1_ISR()
* Description    : The serial port receives the interrupt function to implement circular buffer reception.
*******************************************************************************/
void Uart1_ISR(void) __interrupt (INT_NO_UART1)
{
    if(U1RI)   //Received data
    {
        Receive_Uart_Buf[Uart_Input_Point++] = SBUF1;
        UartByteCount++;                    //Current buffer remaining bytes to be fetched
        if(Uart_Input_Point>=UART_REV_LEN)
            Uart_Input_Point = 0;           //Write pointer
        U1RI =0;
    }

}

void Reset_Uart1()
{
    Uart_Input_Point = 0;   //Circular buffer input pointer
    Uart_Output_Point = 0;  //Circular buffer read pointer
    UartByteCount = 0;      //Current buffer remaining bytes to be fetched

}
#endif
