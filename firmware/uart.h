#ifndef UART_H
#define UART_H

extern void Config_Uart1(uint8_t *cfg_uart);

#if 0
extern void Uart1_ISR(void) __interrupt (INT_NO_UART1);
#endif

#define UART_REV_LEN  4                 //Serial receive buffer size

extern __idata uint8_t Receive_Uart_Buf[UART_REV_LEN];   //Serial receive buffer
extern volatile __idata uint8_t Uart_Input_Point;  //Circular buffer write pointer, set to 0 on reset
extern volatile __idata uint8_t Uart_Output_Point; //Circular buffer fetches the pointer, set to 0 on reset
extern volatile __idata uint8_t UartByteCount;     //Current buffer remaining bytes to be fetched

#endif
