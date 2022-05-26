#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define READ_END_OF_FILE 0
#define WRITE_END_OF_FILE 1

int main(int argc, char** argv)
{
	int my_pipe[2];
	// Create a pipe
	if(pipe(my_pipe)){
		perror("Failed to create pipe\n");
		return -1;
	}
	
	pid_t child = fork();
	if(child == 0){// This is a child process
		close(my_pipe[READ_END_OF_FILE]);
		FILE* out = fdopen(my_pipe[WRITE_END_OF_FILE], "w"); // open up a file, associate a stream with a file descriptor
		sleep(2); 
		fprintf(out, "Are you my parent?"); // print something
		return 42;
	}
	else 
	if(child > 0){	// This is a parent process
		
		close(my_pipe[WRITE_END_OF_FILE]);
		FILE* in = fdopen(my_pipe[READ_END_OF_FILE], "r"); // open up as a file stream, associate a stream with a file descriptor
		char buffer[100];
		
		fgets(buffer, 100, in);
		printf("My child asked \"%s\"\n", buffer);
		
		int status;
		wait(&status);
		printf("And then returned %d\n", WEXITSTATUS(status));
	 }
	 else{
		perror("Failed to fork\n");
		return -1;
	  }
	 return 0;
}

