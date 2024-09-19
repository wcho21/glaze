#include "trap.h"
#include "trap_vector.h"
#include "riscv_csr.h"
#include "riscv_types.h"
#include "task.h"
#include "print.h"
#include "timer.h"

void init_trap(void) {
  write_mtvec((reg)trap_vector);

  write_mstatus(read_mstatus() | MSTATUS_MIE);
}

reg handle_trap(reg epc, reg cause) {
  reg return_pc = epc;
  reg cause_code = cause & 0xfff;

  if ((cause & 0x8000000000000000) == 0) {
    print("Error (Synchronous Trap)\n");
    for (;;) {
      asm volatile("wfi");
    }
  }

  if (cause_code == 7) {
    write_mie(~((~read_mie()) | MIE_MTIE));
    handle_timer();
    return_pc = (reg)&switch_to_os;

    write_mie(read_mie() | MIE_MTIE);
    return return_pc;
  }

  print("Error (Unknown Asynchronous Trap)\n");
  for (;;) {
    asm volatile("wfi");
  }
  return 0;
}
