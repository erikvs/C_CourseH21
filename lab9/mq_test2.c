#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

int msg_count = 0;
pthread_mutex_t mutex;

static void new_msg(union sigval sv){
	struct mq_attr attr;
	ssize_t size;
	char *buf;
	mqd_t queue = *((mqd_t *) sv.sival_ptr);

	// Determine max. msg size; allocate buffer to receive msg
	if (mq_getattr(queue, &attr)){
		perror("mq_getattr\n");
		exit(-1);
	}
	buf = malloc(attr.mq_msgsize);
	if (buf == NULL){
		perror("malloc");
		exit(-1);
	}
	
	size = mq_receive(queue, buf, attr.mq_msgsize, NULL);
	if (size == -1){
		perror("mq_receive\n");
		exit(-1);
	}
	pthread_mutex_lock(&mutex);
	printf("Received message \"%s\"\n", buf);
	fflush(stdout);
	free(buf);
	msg_count ++;
	pthread_mutex_unlock(&mutex);
}

int main(int argc, char** argv){
	mqd_t msg_queue = mq_open("/Introduction2OS-Queue", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP, NULL);
	if(msg_queue == -1)
	{
		perror("mq_open\n");
		return -1;
	}

	// Determine max. msg size; allocate buffer to receive msg
	struct mq_attr attr;
	char *buf;
	if (mq_getattr(msg_queue, &attr)){
		perror("mq_getattr\n");
		exit(-1);
	}
	buf = malloc(attr.mq_msgsize);
	if (buf == NULL){
		perror("malloc");
		exit(-1);
	}	

	
	ssize_t size;
	size = mq_receive(msg_queue, buf, attr.mq_msgsize, NULL);
	if (size == -1){
		perror("mq_receive\n");
		exit(-1);
	}
	printf("Received message \"%s\"\n", buf);
	
	
	size = mq_receive(msg_queue, buf, attr.mq_msgsize, NULL);
	if (size == -1){
		perror("mq_receive\n");
		exit(-1);
	}
	printf("Received message \"%s\"\n", buf);
	
	
	free(buf);
	
	char my_string[] = "My name is Sara";
	
	if( mq_send(msg_queue, my_string, strlen(my_string), 12)){
		perror("mq_send\n");
		return -1;
	}
	return 0;
}
