#include <stdio.h>
#include <math.h>
int Calculate_Product(int A, int B) {
return (A*B);
}
int main() {
int A, B; 
printf("Enter one interger:");
scanf("%d", &A); 
printf("Enter another integer:");
scanf("%d", &B);
printf("Product of entered integers is %d\n", Calculate_Product(A,B));
}
