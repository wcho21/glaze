#include "timer.h"
#include "print.h"
#include "riscv_csr.h"
#include "types.h"

void update_mtimecmp(void);

void init_timer(void) {
  update_mtimecmp();

  write_mtvec((long)handle_timer_interrupt);

  write_mstatus(read_mstatus() | MSTATUS_MIE);

  write_mie(read_mie() | MIE_MTIE);
}

uint64_t callback_timer_function(uint64_t epc) {
  uint64_t return_pc = epc;

  write_mie(~((~read_mie()) | MIE_MTIE));

  print("Callback (Timer)\n");

  update_mtimecmp();

  write_mie(read_mie() | MIE_MTIE);

  return return_pc;
}

void update_mtimecmp(void) {
  *(uint64_t *)(CLINT_MTIMECMP) = *(uint64_t *)(CLINT_MTIME) + TIMER_INTERVAL_CYCLES;
}
