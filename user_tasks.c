#include "user_tasks.h"
#include "task.h"
#include "print.h"

static void user_task1(void);
static void user_task2(void);
static void user_task3(void);
static void delay(void);

void init_user_tasks(void) {
  create_task(&user_task1);
  create_task(&user_task2);
  create_task(&user_task3);
}

static void user_task1(void) {
  for (;;) {
    print("1");
    delay();
  }
}

static void user_task2(void) {
  for (;;) {
    print("2");
    delay();
  }
}

static void user_task3(void) {
  for (;;) {
    print("3");
    delay();
  }
}

static void delay(void) {
  int count = 30000000;
  while (count > 0) {
    count--;
  }
}
