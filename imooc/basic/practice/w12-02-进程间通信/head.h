#ifndef W12_02___HEAD_H_
#define W12_02___HEAD_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define SZ_STR 64

extern void pipe_main01();
extern void pipe_main02();
extern void test01();
extern void test02();
extern void signal_sending();

#endif //W12_02___HEAD_H_
