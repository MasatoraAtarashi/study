#include <stdio.h>

int main(void) 
{
    int height;
    double standard_weight;

    printf("身長を入力してください: ");
    scanf("%d", &height);

    standard_weight = (height - 100) * 0.9;

    printf("標準体重は%5.1fです\n", standard_weight);

    return (0);
}