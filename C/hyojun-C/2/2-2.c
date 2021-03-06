#include <stdio.h>

int main(void) 
{
    int noA, noB;
    puts("整数を入力してください。");
    printf("整数A: ");
    scanf("%d", &noA);
    printf("整数B: ");
    scanf("%d", &noB);

    printf("それらの和は%dで積は%dです。\n", noA + noB, noA * noB);

    return (0);
}