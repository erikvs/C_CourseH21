#include <stdio.h> 
#include <wait.h> 
#include <signal.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>

pid_t pid;
int count = 0;
void handler1(int sig){
    count++;
    printf("count = %d in handler 1\n", count);   
    fflush(stdout);
    kill(pid, SIGUSR1);
}

void handler2(int sig){
    count += 10;
    printf("count = %d in handler 2\n", count);
    exit(0);
}

int main()
{
    pid_t p;
    int status;
    signal(SIGUSR1, handler1);
    if ((pid = fork()) == 0){
        signal(SIGUSR1, handler2);
        kill(getppid(), SIGUSR1);
        while (1);
    }
    if ((p = wait(&status)) > 0){
        count += 100;
        printf("count = %d in main hander\n", count);
    }
    return 0;
}