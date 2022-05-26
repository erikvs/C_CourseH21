#include<stdio.h>
#include <stdlib.h>
int main(){
int *Arr, size, i = 0;
//Receive and store lenght of array
printf("Enter the number of elements in your array:");
scanf("%d", &size);
//Memory allocation
Arr = (int*)malloc(size*sizeof(int));
if (Arr== NULL){
printf("Error in Memory Allocation");
exit (0);
}
//Populate array
printf("Enter %d values of type int to fill the array:", size);
while (i != size) {
scanf("%d", (Arr + i));
i++;
}
//Reverse and print stored array
for(int i = size-1; i >= 0; i--)
printf("%d ", *(Arr + i));
//Memory deallocation
free(Arr);
return 0;
} 
