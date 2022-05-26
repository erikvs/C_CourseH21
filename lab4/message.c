#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"message.h"

static const char* message[] = {
	"Hello!",
	"See you again!",
	"Goodbye!",
	"This is Lab4 assignment!",
	"This course is Introduction to Operating Systems course!"
};

void print_message() {
	int index;
	srand(time(NULL));
	index = rand()/(RAND_MAX/5);
	printf("%s\n", message[index]);
}
