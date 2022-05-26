#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
      int i=0;
      int child = fork();
      if (child == 0) {
          while (1) {
              i++;
              printf("Child is counting at %d\n", i);
              usleep(10000); // Sleep for 1/100 second 
         }
      }
      else {
         printf("Parent sleeping\n");
         sleep(10);
         kill(child, SIGTERM);
         printf("Child has been killed!!!!!!!!!!\n");
         wait(NULL);
         printf("Parent done!\n");
     }
     return 0;
}