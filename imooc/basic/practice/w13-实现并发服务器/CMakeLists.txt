cmake_minimum_required(VERSION 3.16)
project(w13_ C)

set(CMAKE_C_STANDARD 11)

add_executable(w13_ main.c 环形队列设计/shm.c 环形队列设计/shm.h 环形队列设计/sever.c 环形队列设计/client.c 环形队列设计/sem.c 环形队列设计/sem.h 环形队列设计/shmfifo.c 环形队列设计/shmfifo.h 线程池/thread_pool.c 线程池/thread_pool.h 线程池/main.c)
