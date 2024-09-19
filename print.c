#include "print.h"
#include "uart.h"
#include "vararg.h"

#define OUT_BUFFER_SIZE 1024

static int sprintunum(char *out, unsigned int num);
static int sprintstr(char *out, char *str);

static char out_buffer[OUT_BUFFER_SIZE];

void putstr(char *str) {
  for (char *ch = str; *ch != '\0'; ch++) {
    uart_put_char(*ch);
  }
}

int printf(char *format, ...) {
  va_list args;
  va_start(args, format);

  return vprintf(format, args);
}

int vprintf(char *format, va_list args) {
  // TODO: error on buffer overflow

  int length = vsprintf(out_buffer, format, args);
  putstr(out_buffer);

  return length;
}

int vsprintf(char *out, char *format, va_list args) {
  char *out_begin = out;
  char *ch = format;

  for (;;) {
    if (*ch == '\0') {
      *out++ = *ch++;
      break;
    }

    if (*ch != '%') {
      *out++ = *ch++;
      continue;
    }

    ch++;

    if (*ch == 'u') {
      unsigned int num = va_arg(args, unsigned int);
      int length = sprintunum(out, num);

      out += length;
      ch++;
      continue;
    }

    if (*ch == 's') {
      char *str = va_arg(args, char *);
      int length = sprintstr(out, str);

      out += length;
      ch++;
      continue;
    }

    // unexpected format
    *out++ = *ch++;
    *out++ = '\0';
    break;
  }

  int length = (out-1) - out_begin;
  return length;
}

static int sprintunum(char *out, unsigned int num) {
  if (num < 10) {
    *out = '0' + num;
    return 1;
  }

  int length = sprintunum(out, num / 10);
  out[length] = '0' + (num % 10);

  return length+1;
}

static int sprintstr(char *out, char *str) {
  char *out_begin = out;

  for (char *ch = str; *ch != '\0'; ch++) {
    *out++ = *str++;
  }

  return out - out_begin;
}
