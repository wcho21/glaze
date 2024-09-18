#include "print.h"
#include "context.h"
#include "context_switch.h"

__attribute__ ((aligned (16))) char stack[4096];

unsigned char task_stack[4096];

struct context context_init;
struct context context_task;

void user_task(void);

int start(void) {
  print("Hello World!\n");

  context_task.ra = (long)user_task;
  context_task.sp = (long)&task_stack[4095];
  context_switch(&context_init, &context_task);

  return 0;
}

void user_task(void) {
  print("Task Switched!\n");

  for (;;) {
    asm volatile("wfi");
  }
}
