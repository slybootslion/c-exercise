#include "client.h"
#include "shmfifo.h"
#include "msg.h"

#define BLOCK_CNT 10
#define MSG_SZ 64
static shm_fifo_t *g_shmfifo = NULL;
static int g_msgid = 0;

void client_init() {
  g_shmfifo = shmfifo_init(BLOCK_CNT, sizeof(packet_t));
  g_msgid = msg_create();
}

void subscribe(char *topic) {
  packet_t packet;
  pthread_t tid;
  int err = pthread_create(&tid, NULL, do_client_subcribe, NULL);
  if (err != 0) {
	fprintf(stderr, "[ERROR] pthread_create(): %s\n", strerror(err));
	return;
  }
  pthread_detach(tid);
  strcpy(packet.topic, topic);
  packet.pid = getpid();
  packet.mode = SUBSCRIBE;
  shmfifo_put(g_shmfifo, &packet);
}

void publish(char *topic, const char *content) {
  packet_t packet;
// 封装数据包
  strcpy(packet.topic, topic);
  strcpy(packet.content, content);
  packet.pid = getpid();
  packet.mode = PUBLISH;
  shmfifo_put(g_shmfifo, &packet);
}

void *do_client_subcribe(void *arg) {
  char buffer[32] = {0};
  for (;;) {
	memset(buffer, 0, sizeof(buffer));
	msg_recv(g_msgid, getpid(), buffer, MSG_SZ);
	printf("message:<%s>\n", buffer);
  }
  pthread_exit(NULL);
}

