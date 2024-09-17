#define UART_THR (unsigned char*)(0x10000000)
#define UART_LSR (unsigned char*)(0x10000005)

__attribute__ ((aligned (16))) char stack[4096];

int uart_put_char(char ch) {
  // wait until writable
  while ((*UART_LSR & (1 << 6)) == 0);

  // write
  *UART_THR = ch;

  return ch;
}

int start(void) {
  for (char *ch = "Hello World!\n"; *ch != '\0'; ch++) {
    uart_put_char(*ch);
  }

  return 0;
}
