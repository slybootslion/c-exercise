#include "../head.h"

int main() {
  key_t key = ftok(PATHNAME, PRO_ID);

  int shmid = shmget(key, SZ_STR, IPC_CREAT | 0666);
  printf("shmid = %d\n", shmid);

  void *address = shmat(shmid, NULL, 0);

  char buff[SZ_STR] = {0};
  FILE *read_file = fopen("./file_text.txt", "r");
  fgets(buff, SZ_STR, read_file);
  strcpy(address, buff);

  shmdt(address);
  fclose(read_file);

  return 0;
}
