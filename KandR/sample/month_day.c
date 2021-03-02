#include <stdio.h>

void month_day(int year, int yearday, int *pmonth, int *pda);

int main()
{
    int month, day;
    month_day(2020, 61, &month, &day);
    printf("month: %d, day: %d\n", month, day);
    return 0;
}

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

void month_day(int year, int yearday, int *pmonth, int *pda)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pda = yearday;
}
