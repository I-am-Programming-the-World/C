#include <stdio.h>

int main(void) {
    unsigned int counter = 0;
    float grade, total = 0.0, average;

    printf("%s", "Enter grade, -1 to end: ");
    scanf("%f", &grade);

    while (grade != -1) {
        total += grade;
        counter += 1;
        printf("%s", "Enter grade, -1 to end: ");
        scanf("%f", &grade);
    }

    if (counter != 0) {
        average = total / counter;
        printf("Class average is %.2f\n", average);
    } else {
        puts("No grades were entered!\a");
    }

    return 0;
}
/*This program was developed by ©I-am-Programming-the-World*/
                                 