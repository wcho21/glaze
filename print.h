#ifndef PRINT_H
#define PRINT_H

#include "vararg.h"

void print(char *str);
int printf(char *format, ...);
int vprintf(char *format, va_list args);
int vsprintf(char *out, char *format, va_list args);

#endif
