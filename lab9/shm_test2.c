#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "shm_test.h"

int main(int argc, char** argv){
	int fd;
	fd = shm_open("/Introduction2OS", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP); // open the shared memory area, create it if it doesn't exist
	if(!fd){
		perror("shm_open\n");
		return -1;
	}
	if(ftruncate(fd, sizeof(struct SHM_SHARED_MEMORY))){
		perror("ftruncate\n");
		return -1;
	}
	struct SHM_SHARED_MEMORY* shared_mem;
	shared_mem = mmap(NULL, sizeof(struct SHM_SHARED_MEMORY), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(!shared_mem){
		perror("mmap\n");
		return -1;
	}
	if(close(fd)){
		perror("close\n");
		return -1;
	}
	strcpy(shared_mem->a_string, "I am a buffer in the shared memory area");
	shared_mem->an_array[0] = 42;
	sleep(5);
	printf("a_string = \"%s\"\n", shared_mem->a_string);
	printf("an_array[] = {%d, %d, %d, %d, %d}\n", shared_mem->an_array[0], shared_mem->an_array[1], shared_mem->an_array[2], shared_mem->an_array[3], shared_mem->an_array[4]);
	fflush(stdout);
	if(shared_mem->a_ptr > 0){
		printf("a_ptr = %lu = \"%s\"\n", shared_mem->a_ptr, shared_mem->a_ptr);
	}
	else{
		printf("a_ptr = NULL\n");
	}
}

