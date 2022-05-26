#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int count = 0;
pthread_mutex_t lock;
pthread_cond_t goModer;
pthread_cond_t goPfizer;

void* print_Pfizer() { 
	int i;
	
	while (count == 0) { 
	pthread_cond_wait(&goPfizer, &lock);
	pthread_cond_signal(&goModer);
	}

	pthread_mutex_unlock(&lock);
	
	for (i = 0; i < 5; i++) { 
		if (count < 10) { 
			printf("Pfizer\n");
			count++;
			pthread_cond_signal(&goModer);
			pthread_mutex_unlock(&lock);
			pthread_cond_wait(&goPfizer, &lock);
			}
		else
		{ 
			pthread_cond_signal(&goModer);
		}
	}	
}

void* print_Moderna() {
	int i;

	pthread_mutex_lock(&lock);
	
	for (i = 0; i < 6; i++) { 
		if (count < 9) { 
			printf("Moderna\n");
			count++;
			pthread_cond_signal(&goPfizer);
			pthread_mutex_unlock(&lock);
			pthread_cond_wait(&goModer, &lock);
			}
		else
		{ 
			pthread_cond_signal(&goPfizer);
			pthread_mutex_unlock(&lock);	
		}	
	}
}

int main(int argc, char* argv[]) {
	pthread_t t1, t2;
	count = 0;
	
	pthread_mutex_init(&lock, NULL);
	
	pthread_create(&t1, NULL, print_Pfizer, NULL);
	pthread_create(&t2, NULL, print_Moderna, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	printf("Astrazeneca!\n");
	
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&goModer);
	pthread_cond_destroy(&goPfizer);
	
	return 0;
}
