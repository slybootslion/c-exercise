#ifndef W12_02___HEAD_H_
#define W12_02___HEAD_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/signal.h>
#include <sys/sem.h>
#include <pthread.h>
#include <sys/select.h>
#include <poll.h>
#include <sys/epoll.h>

#define SZ_STR 256
#define PATHNAME "."
#define PRO_ID 101

#define SEM_PATHNAME "."
#define SEM_PRO_ID 100

#define SEM_CONTROL_P 0
#define SEM_CONTROL_C 1

extern void pipe_main01();
extern void pipe_main02();
extern void test01();
extern void test02();
extern void signal_sending();
extern void test03();
extern void signal_handle();
extern void test04();
extern void test05();
extern void alram_handle();
extern void test06();
extern void test07();
extern int sem_create(int nsems, unsigned short values[]);
extern int sem_p(int semid, int semnum);
extern int sem_v(int semid, int semnum);
extern int sem_del(int semid);
extern void test08();
extern void sem_handle();
extern void test09();
extern void test10();
extern void fadenkommunikation();
extern void test11();
extern void select_io_exec();
extern void poll_io_exec();
extern void epoll_io_exec();

#endif //W12_02___HEAD_H_
