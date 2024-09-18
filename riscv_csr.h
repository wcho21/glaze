#ifndef RISCV_H
#define RISCV_H

#include "types.h"

#define MSTATUS_MIE (1 << 3)
#define MIE_MTIE (1 << 7)

static inline uint64_t read_mie()
{
  uint64_t x;
  asm volatile("csrr %0, mie" : "=r" (x) );
  return x;
}

static inline void write_mie(uint64_t x)
{
  asm volatile("csrw mie, %0" : : "r" (x));
}

static inline uint64_t read_mstatus()
{
  uint64_t x;
  asm volatile("csrr %0, mstatus" : "=r" (x) );
  return x;
}

static inline void write_mstatus(uint64_t x)
{
  asm volatile("csrw mstatus, %0" : : "r" (x));
}

static inline void write_mtvec(uint64_t x)
{
  asm volatile("csrw mtvec, %0" : : "r" (x));
}

#endif
