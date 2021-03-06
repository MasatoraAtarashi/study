#include <stdio.h>

int main(void) 
{
    int n1, n2;
    double d1, d2;

    n1 = 3;
    n2 = 400;

    d1 = 6.0000;
    d2 = 8.52342;
    
    printf("int * int: %d\n", n1 * n2);
    printf("int * double: %f\n", n1 * d2);
    printf("double * int: %f\n", d1 * n2);
    printf("double * double: %f\n", d1 * d2);

    return (0);
}