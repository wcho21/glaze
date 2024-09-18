#ifndef TIMER_H
#define TIMER_H

#include "types.h"

#define CLINT_MTIMECMP        0x2004000
#define CLINT_MTIME           0x200BFF8

#define TIMER_INTERVAL_CYCLES 10000000

extern void handle_timer_interrupt();

void init_timer(void);
uint64_t callback_timer_function(uint64_t epc);

#endif
