cmake_minimum_required(VERSION 3.16)
project(w13_ C)

set(CMAKE_C_STANDARD 11)

add_executable(w13_ main.c 环形队列设计/shm.c 环形队列设计/shm.h 环形队列设计/sever.c 环形队列设计/client.c 环形队列设计/sem.c 环形队列设计/sem.h 环形队列设计/shmfifo.c 环形队列设计/shmfifo.h 线程池/thread_pool.c 线程池/thread_pool.h 线程池/main.c project/client/client.c project/client/client.h project/server/server.c project/server/server.h project/client/main.c project/client/sem.c project/client/sem.h project/client/shm.c project/client/shm.h project/client/shmfifo.c project/client/shmfifo.h project/server/main.c project/server/shmfifo.c project/server/shmfifo.h project/server/shm.c project/server/shm.h project/server/thread_pool.c project/server/thread_pool.h project/server/sem.c project/server/sem.h 哈希表/hashmap.c 哈希表/hashmap.h 哈希表/main.c 消息队列/msg.c 消息队列/msg.h)
