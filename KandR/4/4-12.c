#include <stdio.h>
#include <string.h>

int itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    char s[1000];
    int n = -2123;

    itoa(n, s);
    printf("%s\n", s);
}

int itoa(int n, char *s)
{
    int pos, sign;

    if ((sign = n) < 0) {
        n = -n;
        *s++ = '-';
    }

    if (n / 10) {
        pos = itoa((n / 10), s);
    }
    *(s + pos++) = n % 10 + '0';
    *(s + pos) = '\0';
    return pos;
}
