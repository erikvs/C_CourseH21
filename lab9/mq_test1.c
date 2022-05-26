#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	mqd_t msg_queue = mq_open("/Introduction2OS-Queue", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP, NULL);
	if(msg_queue == -1){
		perror("mq_open\n");
		return -1;
	}
	
	char my_string1[] = "I am the second year student!";
	char my_string2[] = "I take OS course!\n";
	
	sleep(5);
	
	if( mq_send(msg_queue, my_string1, strlen(my_string1), 27)){
		perror("mq_send");
		return -1;
	}
	
	if( mq_send(msg_queue, my_string2, strlen(my_string2), 42)){
		perror("mq_send");
		return -1;
	}

	// Determine max. msg size; allocate buffer to receive msg
	struct mq_attr attr;
	char *buffer;
	if (mq_getattr(msg_queue, &attr)){
		perror("mq_getattr\n");
		exit(-1);
	}
	buffer = malloc(attr.mq_msgsize);
	if (buffer == NULL){
		perror("malloc");
		exit(-1);
	}

	int priority;
	size_t size = mq_receive(msg_queue, buffer, attr.mq_msgsize, &priority);
	if( size == -1){
		perror("mq_receive");
		return -1;
	}
	printf("Received message \"%s\"\n", buffer);
	mq_unlink("/Introduction2OS-Queue");
	return 0;
}


