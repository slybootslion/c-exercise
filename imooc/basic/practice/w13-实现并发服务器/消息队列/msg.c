#include "msg.h"

#define PATHNAME "."
#define PRO_ID 102
#define MSG_SZ 64

struct msgbuf {
  long mtype;
  char mtext[MSG_SZ];
};

int msg_create() {
  int msgid;
  key_t key = ftok(PATHNAME, PRO_ID);
  msgid = msgget(key, 0);
  if (msgid == -1) {
	msgid = msgget(key, IPC_CREAT | 0644);
	if (msgid == -1) {
	  perror("[ERROR] msgget(): ");
	  return -1;
	}
  }
  return msgid;
}

int msg_send(int msgid, long mtype, char *buf) {
  int ret;
  struct msgbuf msg;
  msg.mtype = mtype;
  strcpy(msg.mtext, buf);
  return msgsnd(msgid, (const void *)&msg, strlen(msg.mtext) + 1, 0);
}
