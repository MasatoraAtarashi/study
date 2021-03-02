#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[], int lim);
void strcat_ori(char s[], char t[]);

int main()
{
    char line[MAXLINE], line2[MAXLINE];
    int fount = 0;

    while (get_line(line, MAXLINE) > 0) {
        get_line(line2, MAXLINE);
        strcat_ori(line, line2);
    }

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void strcat_ori(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
        i++;
    s[--i] = '\0';
    while ((s[i++] = t[j++]) != '\0')
        ;
    printf("line: %s", s);
}
