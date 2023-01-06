#include "client.h"
#include "shmfifo.h"

#define BLOCK_CNT 10
static shm_fifo_t *g_shmfifo = NULL;

void client_init() {
  g_shmfifo = shmfifo_init(BLOCK_CNT, sizeof(packet_t));
}

void subscribe(char *topic) {
  packet_t packet;
  strcpy(packet.topic, topic);
  packet.pid = getpid();
  packet.mode = SUBSCRIBE;

  shmfifo_put(g_shmfifo, &packet);
}
