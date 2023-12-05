#include<stdio.h>
int main ( void ) 
{
    int radius, diameter;
    float PI = 3.14159 , circumference, area;
    
    puts("Enter radius: ");
    scanf("%d", &radius);
    
    diameter = radius * 2;
    circumference = 2 * PI * radius;
    area = PI * (radius * radius);
    
    printf("Diameter = %d\n", diameter);
    printf("Circumference = %f\n", circumference);
    printf("Area = %f\n", area);
    
}
/*This program was developed by ©I-am-Programming-the-World*/
