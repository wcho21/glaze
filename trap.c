#include "trap_vector.h"
#include "task.h"
#include "riscv_csr.h"
#include "types.h"
#include "print.h"
#include "timer.h"

void init_trap(void) {
  write_mtvec((uint64_t)trap_vector);

  write_mstatus(read_mstatus() | MSTATUS_MIE);
}

uint64_t handle_trap(uint64_t epc, uint64_t cause) {
  uint64_t return_pc = epc;
  uint64_t cause_code = cause & 0xfff;

  if ((cause & 0x8000000000000000) == 0) {
    print("Error (Synchronous Trap)\n");
    for (;;) {
      asm volatile("wfi");
    }
  }

  if (cause_code == 7) {
    write_mie(~((~read_mie()) | MIE_MTIE));
    handle_timer();
    return_pc = (uint64_t)&switch_to_os;

    write_mie(read_mie() | MIE_MTIE);
    return return_pc;
  }

  print("Error (Unknown Asynchronous Trap)\n");
  for (;;) {
    asm volatile("wfi");
  }
  return 0;
}
