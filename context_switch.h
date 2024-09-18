#ifndef CONTEXT_SWITCH_H
#define CONTEXT_SWITCH_H

#include "context.h"

extern void context_switch(context *old, context *new);

#endif
