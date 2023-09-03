#include <stdio.h>
int main (void)
{
	int integer1, integer2, average, sum;
	
	puts("Enter first integer:");
	scanf("%d", &integer1);
	
	puts("Enter second integer:");
	scanf("%d", &integer2);
	
	sum = integer1  + integer2;
	average = sum / 2;
	
	printf("Average is %d\n", average);
}
/*This program was developed by ©Zaniar Karimi*/