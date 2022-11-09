#include "../head.h"

int main() {
  key_t key = ftok(PATHNAME, PRO_ID);

  int shmid = shmget(key, SZ_STR, IPC_CREAT | 0666); // 共享内存
  printf("shmid = %d\n", shmid);

  void *address = shmat(shmid, NULL, 0); // 共享内存映射

  char buff[SZ_STR] = {0};
  memcpy(buff, address, SZ_STR);

  FILE *file = fopen("./file_copy.txt", "w");
  fputs(buff, file);

  shmdt(address); //  解除映射
  shmctl(shmid, IPC_RMID, NULL); // 删除共享内存

  fclose(file);

  return 0;
}
