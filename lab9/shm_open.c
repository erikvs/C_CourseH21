#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

<<<<<<< HEAD
struct SHM_SHARED_MEMORY
{
	char a_string[100];
	int an_array[5];
        char *a_ptr;
=======
struct SHM_SHARED_MEMORY{
	char a_string[100];
	int an_array[5];       
>>>>>>> 6711b672bd6a1bf1deab3f0e2a7986a9b785c2f9
};

int main(){
    int fd;
    // open the shared memory area, create it if it doesn't exist
<<<<<<< HEAD
    fd = shm_open("SharedMemory00", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP);
=======
    fd = shm_open("SharedMemory", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP);
>>>>>>> 6711b672bd6a1bf1deab3f0e2a7986a9b785c2f9
    if (!fd) {
        perror("shm_open\n");
        return -1;
    }

    // extend shared memory object as by default it's initialized with size 0
    if(ftruncate(fd, sizeof(struct SHM_SHARED_MEMORY))){
		perror("ftruncate\n");
		return -1;
	}

    struct SHM_SHARED_MEMORY* shared_mem;
    int i;   

      // map shared memory to process address space
<<<<<<< HEAD
       shared_mem = mmap(NULL, sizeof(struct SHM_SHARED_MEMORY), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
       if(!shared_mem){
		perror("mmap\n");
		return -1;
	}
	if(close(fd)){
		perror("close\n");
		return -1;
	}
  // used the share memory
      char mystring[] = "Hello"; 
      
 //     shared_mem->a_string = "Hello";
      strcpy(shared_mem->a_string, "Hello"); 
 
      for (i = 0; i < 5; i++){
               shared_mem->an_array[i] = i*i;
=======
    shared_mem = mmap(NULL, sizeof(struct SHM_SHARED_MEMORY), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(!shared_mem){
	perror("mmap\n");
	return -1;
    }
    if(close(fd)){
	perror("close\n");
	return -1;
     }
     // used the share memory
     char mystring[] = "Hello"; 
     
     //shared_mem->a_string = "Hello";
     strcpy(shared_mem->a_string, "Hello"); 
     for (i = 0; i < 5; i++){
         shared_mem->an_array[i] = i*i;
>>>>>>> 6711b672bd6a1bf1deab3f0e2a7986a9b785c2f9
      }
      printf("Printing values stored in the shared memory ...\n");
      printf("String is %s \n", shared_mem->a_string);
 
      printf("Integers are %d   %d   %d   %d   %d\n", shared_mem->an_array[0], shared_mem->an_array[1], shared_mem->an_array[2], shared_mem->an_array[3], shared_mem->an_array[4]); 
<<<<<<< HEAD
     
      // unmap
      int res = munmap(NULL, sizeof(struct SHM_SHARED_MEMORY));
	if (res == -1)
	{
		perror("munmap");
		return 40;
	}


    return 0;

}
=======
      // unmap
      int res = munmap(NULL, sizeof(struct SHM_SHARED_MEMORY));
      if (res == -1){
	 perror("munmap");
	 return 40;
      }
     return 0;
}
>>>>>>> 6711b672bd6a1bf1deab3f0e2a7986a9b785c2f9
