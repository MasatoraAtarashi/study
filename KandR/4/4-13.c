#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[], int i, int j);

int main()
{
    char s[1000];
    int n = -123;

    itoa(n, s);
    printf("%s\n", s);
}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, 0, strlen(s)-1);
}

void reverse(char s[], int i, int j)
{
    int c;

    c = s[i];
    s[i] = s[j];
    s[j] = c;
    while (i < j) {
        reverse(s, ++i, --j);
    }
}
