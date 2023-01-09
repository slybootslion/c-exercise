#include "msg.h"

int main() {
  int msgid = msg_create();
  char buffer[32] = {0};
  int ret = msg_recv(msgid, 100, buffer, sizeof(buffer));
  if (ret == -1) {
	fprintf(stderr, "msg_recv failed.\n");
	return -1;
  }
  printf("buffer: %s\n", buffer);
  return 0;
}
