#ifndef UART_H
#define UART_H

#include "types.h"

#define UART_THR (uint8_t*)(0x10000000)
#define UART_LSR (uint8_t*)(0x10000005)

char uart_put_char(char ch);

#endif
