# include <stdio.h>

int main(void)
{
    int num;
    printf("整数を入力してください: ");
    scanf("%d", &num);

    if (num >= 0)
        printf("絶対値は%dです。\n", num);
    else
        printf("絶対値は%dです。\n", -num);
        
    return (0);
}