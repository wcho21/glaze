#ifndef CONTEXT_H
#define CONTEXT_H

#include "types.h"

typedef struct _context {
  uint64_t ra;
  uint64_t sp;

  uint64_t s0;
  uint64_t s1;
  uint64_t s2;
  uint64_t s3;
  uint64_t s4;
  uint64_t s5;
  uint64_t s6;
  uint64_t s7;
  uint64_t s8;
  uint64_t s9;
  uint64_t s10;
  uint64_t s11;
} context;

#endif
