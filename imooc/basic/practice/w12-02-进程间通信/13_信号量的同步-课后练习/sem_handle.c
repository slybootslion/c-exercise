#include <time.h>
#include "../head.h"

void create_time_str(FILE *fp) {
  time_t t;
  time(&t);
  struct tm *ptm = localtime(&t);
  int year = ptm->tm_year + 1900;
  int month = ptm->tm_mon + 1;
  int day = ptm->tm_mday;
  int hour = ptm->tm_hour;
  int min = ptm->tm_min;
  int sec = ptm->tm_sec;
  fprintf(fp, " %d-%d-%d %d:%d:%d ", year, month, day, hour, min, sec);
  fflush(fp);
}

void sem_handle() {
  unsigned short values[2] = {1, 0};
  int semid = sem_create(2, values);

  pid_t cpid = fork();

  int count = 0;
  FILE *file_p = fopen("./time.txt", "a");

  if (cpid == 0) {
    while (count++ < 10) {
      sem_p(semid, SEM_CONTROL_C);
      create_time_str(file_p);
      sem_v(semid, SEM_CONTROL_P);
    }
  }
  if (cpid > 0) {
    while (count++ < 10) {
      sem_p(semid, SEM_CONTROL_P);
      fprintf(file_p, "%d,<", count);
      fflush(file_p);
      sem_v(semid, SEM_CONTROL_C);

      sem_p(semid, SEM_CONTROL_P);
      fprintf(file_p, ">\n");
      fflush(file_p);
      sem_v(semid, SEM_CONTROL_P);

      sleep(1);
    }
    wait(NULL);
    sem_del(semid);
    fclose(file_p);
  }
}
