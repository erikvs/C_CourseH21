#include<stdio.h>

int main(){
int i;						//iteration
long long fibArr[50]; 				//defined fibonacci storage array 
long long sum=0; 				//defined sum

fibArr[0] = 0; 				//define two first indices
fibArr[1] = 1;

for (i = 2; i < 51; i++){			//calculate new index value for index 2-50
fibArr[i] = fibArr[i-1] + fibArr[i-2];}

for (i = 0; i < 50; i++){ 		
sum = sum + fibArr[i];}			//add calculated term to total sum of terms

printf("F(50), the 51st term of Fibonacci, is %lld\n", fibArr[50]); 

printf("The sum of the first 50 terms, F(0) through F(49), in the Fibonacci series is %lld\n", sum); 
return 0;
}
