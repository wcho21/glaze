#ifndef TASK_H
#define TASK_H

#include "int_types.h"

#define MAX_TASKS 16

typedef void (*task)(void);
typedef uint32 task_id;

extern task_id next_task_id;

task_id create_task(task task);
void switch_to_task(task_id i);
void switch_to_os(void);

#endif
