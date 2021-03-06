# include <stdio.h>

int main(void)
{
    int a, b, c;
    puts("三つの整数を入力してください。");
    printf("整数A: ");
    scanf("%d", &a);
    printf("整数B: ");
    scanf("%d", &b);
    printf("整数C: ");
    scanf("%d", &c);

    printf("最小値は%dです", (a < b) ? (a < c) ? a : c : (b < c) ? b : c);

    return (0);
}