#include "server.h"
#include "thread_pool.h"
#include "shmfifo.h"
#include "hashmap.h"

#define BLOCK_CNT 10
#define THREAD_CNT 10
#define TASK_CNT 10
#define DEBUG

static shm_fifo_t *g_shmfifo = NULL;
static tpool_t *g_tpool = NULL;
static hashtable_t **g_hashtable = NULL;

void task_handler(void *arg) {
  packet_t *packet = (packet_t *)arg;
  if (packet->mode == PUBLISH) printf("publish.\n");
  else if (packet->mode == SUBSCRIBE) {
	printf("subscribe.\n");
	do_subscribe(packet->topic, packet->pid);
  }
}

void server_init() {
  g_shmfifo = shmfifo_init(BLOCK_CNT, sizeof(packet_t));
  g_tpool = thread_pool_init(THREAD_CNT, TASK_CNT);
  g_hashtable = create_hashtable();
}

void do_subscribe(char *topic, pid_t pid) {
  datatype_t value;
  strcpy(value.topic, topic);
  value.pid = pid;

  insert_data_hash(g_hashtable, topic, value);
#ifdef DEBUG
  printf_hash_table(g_hashtable);
#endif
}

void run_loop() {
  packet_t *packet = NULL;
  for (;;) {
	packet = (packet_t *)malloc(sizeof(packet_t));
	memset(packet, 0, sizeof(packet_t));
	shmfifo_get(g_shmfifo, packet);
#ifdef DEBUG
	printf("topic: %s, pid: %d, content: %s, mode: %d\n",
		   packet->topic, packet->pid, packet->content, packet->mode);
	thread_pool_add_task(g_tpool, task_handler, (void *)packet);
#endif
  }
}
