//
// Created by SlybootsLion on 2022/10/11.
//
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stdout, "Usage: %s <pathname> \n", argv[0]);
    return -1;
  }

  FILE *fp = fopen(argv[1], "w+");
  // <2022-5-8 23::15:00>

  time_t t;
  time(&t);
  struct tm *ptm = localtime(&t);
  int year = ptm->tm_year + 1900;
  int month = ptm->tm_mon + 1;
  int day = ptm->tm_mday;
  int hour = ptm->tm_hour;
  int min = ptm->tm_min;
  int sec = ptm->tm_sec;

  fprintf(fp, "<%d-%d-%d %d:%d:%d>", year, month, day, hour, min, sec);

  fclose(fp);

  return 0;
}
