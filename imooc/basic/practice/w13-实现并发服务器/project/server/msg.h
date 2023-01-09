#ifndef W13___MSG_H_
#define W13___MSG_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

extern int msg_create();
extern int msg_send(int msgid, long mtype, char *buf);
extern int msg_recv(int msgid, long mtpye, char *buf, int len);
extern int msg_del(int msgid);

#endif //W13___MSG_H_
