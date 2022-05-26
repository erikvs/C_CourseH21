#include <stdio.h>
#include <stdlib.h>
int main() {
FILE* myFile;
myFile = fopen("testcase0.txt", "r"); 		//define external source 
//myFile = fopen("testcase1.txt", "r"); 		//external source for second part of exercise

int i, loopCount, num;
long long sum = 0;					//sum variable - assumes large 
	
if (myFile == NULL) {					//error handling
printf("Error Reading File\n");
exit(0);}

fscanf(myFile, "%d", &loopCount);			//scan first line of doc and assign this value, total number of elements, as value for loopCount

for (i = 0; i < loopCount; i++) {			//for each index up to loopCount
fscanf(myFile, "%d", &num);				//grab the value and store it in num

sum += num;}						//add value of num to sum
printf("The sum of elements is %lld\n", sum); 	

fclose(myFile);
return 0;
}
