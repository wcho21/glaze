#include "timer.h"
#include "print.h"
#include "riscv_csr.h"
#include "riscv_types.h"
#include "int_types.h"
#include "task.h"

reg scratch[32];

static void update_mtimecmp(void);

void init_timer(void) {
  update_mtimecmp();

  write_mscratch((reg)scratch);

  write_mie(read_mie() | MIE_MTIE);
}

void handle_timer(void) {
  update_mtimecmp();
}

static void update_mtimecmp(void) {
  *(reg *)(CLINT_MTIMECMP) = *(reg *)(CLINT_MTIME) + TIMER_INTERVAL_CYCLES;
}
