#include "cmd_handle.h"

#define SZ_CMD 64

int main() {
  char command[SZ_CMD] = {0};

  for (;;) {
    printf("TinyShell >");
    fgets(command, SZ_CMD, stdin);

    command[strlen(command) - 1] = '\0';

    if (strncmp(command, "quit", 4) == 0) {
      printf("Goodbye\n");
      break;
    }

    cmd_execute(command);
  }

  return 0;
}
