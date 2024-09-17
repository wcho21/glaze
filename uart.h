#ifndef UART_H
#define UART_H

#define UART_THR (unsigned char*)(0x10000000)
#define UART_LSR (unsigned char*)(0x10000005)

int uart_put_char(char ch);

#endif
