#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char s[], int lim);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    int fount = 0;

    while (get_line(line, MAXLINE) > 0) {
        int i;
        if ((i = strrindex(line, pattern)) >= 0) {
            printf("pattern is found in '%s', idx: %d\n", line, i);
            fount++;
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

int strrindex(char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s)-1; i >= 0; i--) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

