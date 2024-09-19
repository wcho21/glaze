#include "error.h"
#include "print.h"

void error(char* reason) {
  print("Error: ");
  print(reason);
  print("\n");

  for (;;) {
    asm volatile("wfi");
  }
}
