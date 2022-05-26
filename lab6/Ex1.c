#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* The following function is run by the second thread */
void *Increase(void *a_void_ptr){
     /* Increase a to 100 */
      int *a_ptr = (int *)a_void_ptr;

      // YOUR CODE HERE
      printf("Increasing a finished thanks to the second thread\n");
}

int main(){

       int a = 0, b = 1000;

       /* Show the initial values of a and b */
       printf("Initial values: a = %d, b = %d\n", a, b);

        /* Variable for the second thread */
        pthread_t increaseThread;

        // YOUR CODE HERE

        printf("Final values: a= %d, b= %d\n", a, b);
        return 0;
}
