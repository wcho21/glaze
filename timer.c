#include "timer.h"
#include "print.h"
#include "riscv_csr.h"
#include "types.h"
#include "task.h"

uint64_t scratch[32];

static void update_mtimecmp(void);

void init_timer(void) {
  update_mtimecmp();

  write_mscratch((uint64_t)scratch);

  write_mie(read_mie() | MIE_MTIE);
}

void handle_timer(void) {
  update_mtimecmp();
}

static void update_mtimecmp(void) {
  *(uint64_t *)(CLINT_MTIMECMP) = *(uint64_t *)(CLINT_MTIME) + TIMER_INTERVAL_CYCLES;
}
