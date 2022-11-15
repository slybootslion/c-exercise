cmake_minimum_required(VERSION 3.16)
project(w12_02_ C)

set(CMAKE_C_STANDARD 11)

add_executable(w12_02_ main.c 01_无名管道.c head.h 01_无名管道作业.c 04_raise函数.c 05_等待信号.c 06_信号的发送-课后任务.c 07_用户自定义处理.c 08_信号的处理-课后练习.c 09_alarm函数.c 10_消息队列01.c 09_alram与子进程退出信号-课后练习.c 12_资源竞争.c 13_信号量同步.c 13_信号量的同步-课后练习/sem_handle.c 17_多路复用IO_select.c 18_多路复用IO_poll.c)
