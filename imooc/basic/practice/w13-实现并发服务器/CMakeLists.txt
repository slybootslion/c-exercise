cmake_minimum_required(VERSION 3.16)
project(w13_ C)

set(CMAKE_C_STANDARD 11)

add_executable(w13_ main.c shm.c shm.h sever.c client.c sem.c sem.h shmfifo.c shmfifo.h)
