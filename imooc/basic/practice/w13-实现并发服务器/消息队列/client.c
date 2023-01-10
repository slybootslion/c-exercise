#include "msg.h"

int main() {
  int msgid = msg_create();
  char buffer[32] = "hello msg";
  msg_send(msgid, 100, buffer);
  return 0;
}
