#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void escape(char s[], char t[]);

int main()
{
    int len;
    char s[MAXLINE], t[MAXLINE];
    while ((len = get_line(s, MAXLINE)) > 0)
        escape(s, t);
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void escape(char s[], char t[]) {
    int i, j;
    for (i=j=0; i<strlen(s)-1; i++) {
        switch (s[i]) {
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }
    printf("result: %s\n", t);
}
