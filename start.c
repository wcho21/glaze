#include "print.h"
#include "context.h"
#include "context_switch.h"
#include "types.h"
#include "timer.h"
#include "riscv_memory.h"

__attribute__ ((aligned (16))) uint8_t stack[STACK_SIZE];

uint8_t task_stack[4096];

context context_init;
context context_task;

void user_task(void);

void start(void) {
  print("Hello World!\n");

  init_timer();

  context_task.ra = (uint64_t)user_task;
  context_task.sp = (uint64_t)&task_stack[4095];
  context_switch(&context_init, &context_task);
}

void user_task(void) {
  print("Task Switched!\n");

  for (;;) {
    asm volatile("wfi");
  }
}
