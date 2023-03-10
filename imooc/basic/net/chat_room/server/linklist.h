#ifndef CHAT_ROOM_LINKLIST_H
#define CHAT_ROOM_LINKLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

typedef struct sockaddr_in datatype_t;
typedef struct node
{
	datatype_t data;
	struct node* next;
} linknode_t;

extern linknode_t* create_empty_linklist();

extern void insert_head_linklist(linknode_t* head, datatype_t data);

extern int find_linklist(linknode_t* head, datatype_t* data);

extern void broadcast_message(int sockfd, linknode_t* head, char* msg, int msg_len);

#endif //CHAT_ROOM_LINKLIST_H
