#ifndef RISCV_CSR_H
#define RISCV_CSR_H

#include "riscv_types.h"

#define MSTATUS_MIE (1 << 3)
#define MIE_MTIE (1 << 7)

static inline reg read_mie()
{
  reg x;
  __asm__ volatile("csrr %0, mie" : "=r" (x) );
  return x;
}

static inline void write_mie(reg x)
{
  __asm__ volatile("csrw mie, %0" : : "r" (x));
}

static inline reg read_mstatus()
{
  reg x;
  __asm__ volatile("csrr %0, mstatus" : "=r" (x) );
  return x;
}

static inline void write_mstatus(reg x)
{
  __asm__ volatile("csrw mstatus, %0" : : "r" (x));
}

static inline void write_mtvec(reg x)
{
  __asm__ volatile("csrw mtvec, %0" : : "r" (x));
}

static inline void write_mscratch(reg x)
{
  __asm__ volatile("csrw mscratch, %0" : : "r" (x));
}

#endif
