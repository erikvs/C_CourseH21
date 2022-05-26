/* This C program uses mutex to access critical section
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <pthread.h>

pthread_mutex_t mutex;  //global variable mutex declaration			

int count;              //global variable count declaration			


void Increase(void){   
int i;		
int temp;

	for( i = 0; i < 100; i++){   
		pthread_mutex_lock(&mutex);
		temp = count + 10;		
		usleep(1);			
		count = temp;  
		pthread_mutex_unlock(&mutex);  		
	}
}

void Decrease(void){		
int  i;
int  temp;
  
	for(i = 0; i < 100; i++){
		pthread_mutex_lock(&mutex);  
		temp  = count - 10;
		usleep(2);			
		count = temp;  		
		pthread_mutex_unlock(&mutex);
	}
}

int main (int argc, char *argv[]){
pthread_t t1;			
pthread_t t2; 

count = 0;      // global variable unitialization 

pthread_mutex_init(&mutex, NULL);	// mutex unitialization

pthread_create(&t1, NULL, (void*)&Increase, NULL);
pthread_create(&t2, NULL, (void*)&Decrease, NULL); 

pthread_join(t1, NULL);
pthread_join(t2, NULL);

printf("global variable count is: %d\n",count);

return 0;
}
