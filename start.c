#include "uart.h"

__attribute__ ((aligned (16))) char stack[4096];

int start(void) {
  for (char *ch = "Hello World!\n"; *ch != '\0'; ch++) {
    uart_put_char(*ch);
  }

  return 0;
}
