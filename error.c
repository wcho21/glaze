#include "error.h"
#include "print.h"

void error(char* reason) {
  printf("Error: %s\n", reason);

  for (;;) {
    __asm__ volatile("wfi");
  }
}
