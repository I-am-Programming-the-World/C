#include <stdio.h>
int main (void)
{
	int num1, num2;
 
	puts("Enter two numbers and i will tell you");
	puts("the relationship they satisfy.");
	
	scanf("%d%d", &num1, &num2);
	
	if ( num1 == num2 ) {
		printf("%d is equal to %d\t", num1, num2 );
	}
	if ( num1 != num2 ) {
		printf("%d is not equal to %d\t", num1, num2 );
	}
	if ( num1 < num2 ) {
		printf("%d is less than %d\t", num1, num2 );
	}
	if ( num1 > num2 ) {
		printf("%d is greater than %d\t", num1, num2 );
	}
	if ( num1 <= num2 ) {
		printf("%d is less than or equal to %d\t", num1, num2 );
	}
	if ( num1 >= num2 ) {
		printf("%d is greater than or equal to %d\t", num1, num2 );
	}
}
/*This program was developed by ©I-am-Programming-the-World*/
