#include <stdio.h>
int square ( int );
int main ( void )
{
    int a;
    scanf("%d", &a);
    printf("%d squared: %d\n", a, square ( a ) );
}
int square ( int x )
{
    return x * x;
}
/*This program was developed by ©I-am-Programming-the-World*/
