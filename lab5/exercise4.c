#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t child = fork();

	
    if (child > 0) { //parent runs this
    	printf("Parent ID %d\n", getpid());
	printf("Child ID %lu\n", child);
        sleep(200);
        }
        
    else {	//child runs this
        exit(0);
    }

    return 0;
}
