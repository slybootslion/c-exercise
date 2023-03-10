#include "linklist.h"

linknode_t* create_empty_linklist() {
	linknode_t* head = NULL;
	head = (linknode_t*)malloc(sizeof(linknode_t));
	if (head == NULL) {
		printf("malloc is fail!\n");
		return NULL;
	}
	memset(head, 0, sizeof(linknode_t));
	return head;
}

void insert_head_linklist(linknode_t* head, datatype_t data) {
	linknode_t* temp = (linknode_t*)malloc(sizeof(linknode_t));
	if (temp == NULL) {
		printf("malloc is fail!\n");
		return;
	}
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

int find_linklist(linknode_t* head, datatype_t* data) {
	linknode_t* p = head;
	while (p->next != NULL) {
		if (memcmp(&(p->data), data, sizeof(datatype_t)) == 0)
			return 1;
		p = p->next;
	}
	return 0;
}

void broadcast_message(int sockfd, linknode_t *head, char *msg, int msg_len) {
	linknode_t *p = head;
	while (p->next){
		sendto(sockfd, msg, msg_len, 0, (struct sockaddr*)&(p->next->data), sizeof(datatype_t));
		p = p->next;
	}
}
