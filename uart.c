#include "uart.h"

char uart_put_char(char ch) {
  // wait until writable
  while ((*UART_LSR & (1 << 6)) == 0);

  // write
  *UART_THR = ch;

  return ch;
}
