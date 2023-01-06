#ifndef W13__PROJECT_SERVER_SERVER_H_
#define W13__PROJECT_SERVER_SERVER_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

enum work_mode {
  PUBLISH = 0, // 发布
  SUBSCRIBE, // 订阅
};

#define TOPIC_SZ 64
#define CONTENT_SZ 64
typedef struct packet {
  char topic[TOPIC_SZ]; // 主题内容
  pid_t pid;
  enum work_mode mode;
  char content[CONTENT_SZ];
} packet_t;

extern void server_init();
extern void run_loop();

extern void do_subscribe(char *topic, pid_t pid);

#endif //W13__PROJECT_SERVER_SERVER_H_
