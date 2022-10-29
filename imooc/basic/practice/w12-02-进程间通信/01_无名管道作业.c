#include "head.h"

void pipe_main02() {
  int pipefd[2];

  int ret = pipe(pipefd);
  if (ret == -1) {
    perror("[ERROR] pipe(): ");
    exit(EXIT_FAILURE);
  }

  pid_t cpid = fork();
  if (cpid == -1) {
    perror("[ERROR] fork(): ");
    exit(EXIT_FAILURE);
  } else if (cpid == 0) {
    while (1) {
      char output_str[SZ_STR] = {0};
      ssize_t rbytes = read(pipefd[0], output_str, sizeof(output_str));
      if (rbytes == -1) {
        perror("[ERROR] read(): ");
        close(pipefd[0]);
        exit(EXIT_FAILURE);
      }

      if (!strcmp(output_str, "quit")) {
        int pid = getppid();
        close(pipefd[0]);
        kill(pid, SIGKILL);
        close(pipefd[1]);
        wait(NULL);
        exit(EXIT_SUCCESS);
      }
      printf("print string --> %s\n", output_str);
    }
    close(pipefd[0]);
  } else if (cpid > 0) {
    while (1) {
      char input_str[SZ_STR] = {0};
      sleep(1);
      printf("input string -->");
      fgets(input_str, SZ_STR, stdin);
      input_str[strlen(input_str) - 1] = '\0';

      close(pipefd[0]);
      size_t wbytes = write(pipefd[1], input_str, strlen(input_str));
      if (wbytes == -1) {
        perror("[ERROR] write()");
        wait(NULL);
        close(pipefd[1]);
        exit(EXIT_FAILURE);
      }
    }
  }
}
