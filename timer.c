#include "timer.h"
#include "print.h"
#include "riscv_csr.h"
#include "types.h"

void init_timer(void) {
  *(long *)(CLINT_MTIMECMP) = *(long *)(CLINT_MTIME) + TIMER_INTERVAL_CYCLES;

  write_mtvec((long)handle_timer_interrupt);

  write_mstatus(read_mstatus() | MSTATUS_MIE);

  write_mie(read_mie() | MIE_MTIE);
}

uint64_t callback_timer_function(uint64_t epc) {
  uint64_t return_pc = epc;

  write_mie(~((~read_mie()) | MIE_MTIE));

  print("Callback (Timer)\n");

  *(long *)CLINT_MTIMECMP = *(long *)CLINT_MTIME + TIMER_INTERVAL_CYCLES;

  write_mie(read_mie() | MIE_MTIE);

  return return_pc;
}
