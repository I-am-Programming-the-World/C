#include <stdio.h>
int main ( void )
{
	float number, square, cube;
	
	printf("%s","Enter a number and I will give you ");
	printf("the Square and Cube values:\n");
	
	scanf("%f", &number);
	
	square = number * number ;
	
	cube = square * number ;
	
	printf("Square is:%.6f", square );
	printf("\nCube is:%.6f", cube );
}
/*This program was developed by ©I-am-Programming-the-World*/
	
