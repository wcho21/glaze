#include "print.h"
#include "uart.h"

void print(char *str) {
  for (char *ch = str; *ch != '\0'; ch++) {
    uart_put_char(*ch);
  }
}
