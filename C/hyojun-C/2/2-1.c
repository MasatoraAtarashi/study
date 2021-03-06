#include <stdio.h>

int main(void) 
{
    double noA, noB;
    puts("整数を入力してください。");
    printf("整数A: ");
    scanf("%lf", &noA);
    printf("整数B: ");
    scanf("%lf", &noB);

    printf("Aの値はBの%d%%です。\n", (int)(noA / noB * 100));

    return (0);
}