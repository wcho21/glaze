#ifndef CONTEXT_H
#define CONTEXT_H

#include "riscv_types.h"

typedef struct _context {
  reg ra;
  reg sp;

  reg s0;
  reg s1;
  reg s2;
  reg s3;
  reg s4;
  reg s5;
  reg s6;
  reg s7;
  reg s8;
  reg s9;
  reg s10;
  reg s11;
} context;

#endif
