# include <stdio.h>

int main(void)
{
    int a, b, c, min;
    puts("三つの整数を入力してください。");
    printf("整数A: ");  scanf("%d", &a);
    printf("整数B: ");  scanf("%d", &b);
    printf("整数C: ");  scanf("%d", &c);

    if (a == b && b == c)
        puts("三つの値は等しいです。");
    else if (a == b || b == c)
        puts("二つの値は等しいです。");
    else
        puts("三つの値は異なります。");

    return (0);
}