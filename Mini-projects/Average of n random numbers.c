#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main( void )
{
    int n , sum = 0 , i = 1;
    float average;
    srand ( time(NULL) );
    puts ("Enter a number: ");
    scanf("%d", &n);
    while ( i <= n ) {
        sum += rand();
        i++;
    }
    average = ( float )sum / i;
    printf("Average is %f", average );
}
/*This program was developed by ©Zaniar Karimi*/