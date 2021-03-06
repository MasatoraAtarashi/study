#include <stdio.h>

int main(void) 
{
    double no;
    printf("実数を入力してください: ");
    scanf("%lf", &no);

    printf("あなたは%fと入力しましたね。\n", no);

    return (0);
}