#include <stdio.h>
int main ( void )
{
    int i , index = 0;
    float a, max = 0.0;
    for ( i = 1 ; i <= 10;) {
        printf("Enter the grade of student <%d>", i);
        scanf("%f", &a);
        if ( a < 0 ) {
            continue;
        }
        if ( a > max ) {
            max = a;
            index = i;
        }
        i++;
    }
    printf("\nThe grade of the top student is : <%d , %g>", index , max );
}
/*This program was developed by ©I-am-Programming-the-World*/
