#include<stdio.h>
int main ( void )
{
	float Height, Weight, BMI, Gain, Lose;
	float U = 18.5 , N = 25 , O = 30;//Global standards for BMI calculation
	
	printf("%s%s","Enter you Weight & Height respectively in ",
		"(KG & Meters) and I will give you BMI:\n");	
	scanf("%f%f", &Weight, &Height);
	
	BMI = ( float )Weight / ( Height * Height );
	//( Height * Height ) = pow( Height, 2 ) ------>#include<math.h>	
	Gain = (float) ( ( N + U ) / 2  * ( Height * Height ) - Weight );
	//( Height * Height ) = pow( Height, 2 ) ------>#include<math.h>
	Lose = (float) Weight - ( ( N + U ) /2  * ( Height * Height ) );
	//( Height * Height ) = pow( Height, 2 ) ------>#include<math.h>
	if( BMI <= U ) {
		printf("Current BMI is: %f\t", BMI);	
		printf("you are underweight\nGain:%fKG\n", Gain);
	}//end if
	else {
		if( U < BMI && BMI <= N ) {
			printf("Current BMI is: %f\t\n", BMI);
			printf("You have a normal BMI.\n");
		}//end first inner if
		if( N < BMI && BMI <= O  ) {
			printf("Current BMI is: %f\n", BMI);
			printf("You Are OverWeight!!! Sorry but you need to lose:%fKG\n", Lose);
		}//end second inner if
		if( BMI > O ) {
			printf("Current BMI is: %f\n", BMI);
			printf("YOU ARE OBESE!!!!!! YOU MUST LOSE:%fKG\n", Lose);
		}//end third inner if
	}//end else
}//end main
/*This program was developed by ©I-am-Programming-the-World*/