#include "print.h"
#include "context.h"
#include "context_switch.h"
#include "types.h"

__attribute__ ((aligned (16))) char stack[4096];

uint8_t task_stack[4096];

struct context context_init;
struct context context_task;

void user_task(void);

int start(void) {
  print("Hello World!\n");

  context_task.ra = (uint64_t)user_task;
  context_task.sp = (uint64_t)&task_stack[4095];
  context_switch(&context_init, &context_task);

  return 0;
}

void user_task(void) {
  print("Task Switched!\n");

  for (;;) {
    asm volatile("wfi");
  }
}
