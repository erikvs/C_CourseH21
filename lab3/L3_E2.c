#include<stdio.h>
#include<stdlib.h>
int main(){
FILE* myFile;
myFile = fopen("Input.dat", "r"); 
int row, col, big = 0, **a; //rows, columns, biggest int, matrix

//Error handling
if (myFile == NULL) {					
printf("Error Reading File\n");
exit(0);}

//read first two elements of file and assign their value to adress of row and col
fscanf(myFile, "%d%d", &row, &col); 

//Allocate memory to matrix
a = (int **) malloc(row * sizeof(int *));
for(int i=0; i<row; i++){
a[i] = (int *) malloc(col * sizeof(int));
}
//Populate matrix
for (int j=0; j<row; j++) {
for (int k=0; k<col; k++){
fscanf(myFile,"%d", (*(a + j) + k));
}}

//Matrix printing
for (int j=0; j<row; j++) {
for (int k=0; k<col; k++) {
printf("%d", *(*(a + j) + k));
//Find biggest number in matrix
if ( *(*(a + j) + k) > big ) {
big = *(*(a + j) + k);
}
printf(" ");
}
printf("\n");
}
printf("\n");
printf("Biggest number is:%d", big);
//Memory deallocation
free(a);
fclose(myFile);
return 0;
}
