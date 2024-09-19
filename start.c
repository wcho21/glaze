#include "print.h"
#include "int_types.h"
#include "timer.h"
#include "riscv_memory.h"
#include "user_tasks.h"
#include "task.h"
#include "trap.h"

__attribute__ ((aligned (16))) uint8 stack[STACK_SIZE];

static void schedule_user_tasks();

void start(void) {
  printf("Booting: OK\n");

  init_user_tasks();
  init_trap();
  init_timer();

  schedule_user_tasks();
}

static void schedule_user_tasks() { // round-robin
  task_id next = 0;

  for (;;) {
    switch_to_task(next);
    next = (next + 1) % next_task_id;
  }
}
