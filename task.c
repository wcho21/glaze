#include "task.h"
#include "types.h"
#include "context.h"
#include "context_switch.h"
#include "riscv_memory.h"

static uint8_t task_stacks[MAX_TASKS][STACK_SIZE];
static context task_contexts[MAX_TASKS];
task_id next_task_id = 0;

static context *active_context;
static context os_context;

static task_id allocate_task_id(void);

task_id create_task(task task) {
  task_id id = allocate_task_id();

  // initialize context
  context *context = &task_contexts[id];
  context->ra = (uint64_t) task;
  context->sp = (uint64_t) &task_stacks[id][STACK_SIZE-1];

  return id;
}

void switch_to_task(task_id i) {
  active_context = &task_contexts[i];
  context_switch(&os_context, active_context);
}

#include "print.h"
void switch_to_os(void) {
  context_switch(active_context, &os_context);
}

static task_id allocate_task_id(void) {
  return next_task_id++;
}
