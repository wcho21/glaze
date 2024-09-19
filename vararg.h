#ifndef VARARG_H
#define VARARG_H

typedef __builtin_va_list va_list;

#define va_start(v, args)  (__builtin_va_start(v, args))
#define va_arg(v, t)    (__builtin_va_arg(v, t))

#endif
