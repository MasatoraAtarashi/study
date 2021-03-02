#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char s[], int lim);
int strend(char *s, char *t);

char *pattern = "abc";

int main()
{
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        if (strend(line, pattern) > 0) {
            printf("pattern is found in end of %s\n", line);
        } else {
            printf("pattern is not found\n");
        }
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strend(char *s, char *t)
{
    int t_idx = strlen(t);
    while (*s)
        s++;
    while (*t)
        t++;
    while (*s-- == *t--)
        t_idx--;
    if (t_idx < 0)
        return 1;
    return 0;
}

