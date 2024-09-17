#ifndef CONTEXT_SWITCH_H
#define CONTEXT_SWITCH_H

#include "context.h"

extern void context_switch(struct context *old, struct context *new);

#endif
