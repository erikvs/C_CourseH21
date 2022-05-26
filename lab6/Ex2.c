#include <stdlib.h> 
#include <pthread.h> 
#include <errno.h> 
#include <stdio.h>
void Thread1Print(void) {
    printf("This is Thread 1\n");
}
void Thread2Print(void) {
    printf("This is Thread 2\n");
}
int main(int argc, char** argv) {
    int err = 0;
    pthread_t t1;
    pthread_t t2;

    err = pthread_create(&t1, NULL, (void*)Thread1Print, NULL);
    if (err != 0) {
        perror("ERROR in creating thread");
        exit(1);
    }
    err = pthread_create(&t2, NULL, (void*)Thread1Print, NULL);
    if (err != 0) {
        perror("ERROR in creating thread");
        exit(1);
    }
    printf("I am the main thread\n");
    return 0;
}