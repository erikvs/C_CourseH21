#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
void my_routine( ) {
     printf("Signal handling\n");
     printf("......");
}
int main( ) {
     signal(SIGINT, my_routine);
     printf("Entering infinite loop\n");
     while(1) {
        sleep(10);
     } 
     printf("Never get there\n");
}
