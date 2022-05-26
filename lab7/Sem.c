#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>

sem_t dep;
sem_t fac;

void* print_Department() { 
	int i;
	
	for (i = 0; i < 5; i++) { 
		printf("Department of Computer Science and Communication\n");
		sem_post(&fac);
		sem_wait(&dep);
	}	
	sem_post(&fac);
}


void* print_Faculty() {
	int i;
	
	sem_wait(&fac);
	for (i = 0; i < 5; i++) { 
		printf("Faculty of Computer Science, Engineering and Economics\n\n");

		sem_post(&dep);
		sem_wait(&fac);
	}		
	sem_post(&dep);	
}

int main(int argc, char* argv[]) {
	sem_init(&dep, 0, 0);
	sem_init(&fac, 0, 0);
	pthread_t t1, t2;			
	
	printf("Ostfold University College!\n\n");
	
	pthread_create(&t1, NULL, print_Department, NULL); 
	pthread_create(&t2, NULL, print_Faculty, NULL); 
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	sem_destroy(&dep);
	sem_destroy(&fac);

	return 0;
}
