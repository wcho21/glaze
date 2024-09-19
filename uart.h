#ifndef UART_H
#define UART_H

#include "int_types.h"

#define UART_THR (uint8*)(0x10000000)
#define UART_LSR (uint8*)(0x10000005)

char uart_put_char(char ch);

#endif
