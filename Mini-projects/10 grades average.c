#include <stdio.h>
int main ( void )
{
	unsigned int counter;
	int grade, total, average;
	
	total = 0;
	counter = 1;
	
	while ( counter <= 10 ) {
		printf( "%s", "Enter grade: ");
		scanf("%d", &grade );
		
		total = total + grade;//total += grade;
		counter = counter + 1;//counter++;
	}
	average = total / 10;// average = total / counter;
	
	printf("class avrage is %d\n", average );
}
/*This program was developed by ©I-am-Programming-the-World*/
