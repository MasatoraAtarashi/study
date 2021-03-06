# include <stdio.h>

int main(void)
{
    int a, b, c, d, max;
    puts("四つの整数を入力してください。");
    printf("整数A: ");
    scanf("%d", &a);
    printf("整数B: ");
    scanf("%d", &b);
    printf("整数C: ");
    scanf("%d", &c);
    printf("整数D: ");
    scanf("%d", &d);

    max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    printf("最小値は%dです", max);

    return (0);
}