#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    fork();
    fork();
    printf("Process %d's parent process ID is %d\n", getpid(), getppid());
    sleep(2);
    return 0;
}
