#include<stdio.h>
int main( void ) 
{
	unsigned int sum, x;
	x = 1;
	sum = 0;
	
	while ( x <= 10 ) {
		sum += x;
		++x;
	}
	printf("The sum is: %u\n", sum);
}
/*This program was developed by ©I-am-Programming-the-World*/
