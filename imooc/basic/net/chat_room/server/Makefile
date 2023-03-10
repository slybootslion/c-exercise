CC = gcc
CFLAGS = -Wall -Werror

# 指定需要编译的源代码文件和输出的可执行文件
SRCS = linklist.c udp_server.c
OBJS = $(SRCS:.c=.o)
TARGET = server

# 指定生成可执行文件的编译规则
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# 指定每个源代码文件的编译规则
linklist.o: linklist.c linklist.h
	$(CC) $(CFLAGS) -c linklist.c

udp_server.o: udp_server.c linklist.h
	$(CC) $(CFLAGS) -c udp_server.c

# 指定清理规则
clean:
	rm -f $(TARGET) $(OBJS)
