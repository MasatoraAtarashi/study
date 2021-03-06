#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000

int htoi(char s[]);
int get_line(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];
    while ((len = get_line(line, MAXLINE)) > 0) {
        int i = htoi(line);
        printf("%d\n", i);
    }
    return 0;
}

int htoi(char s[]) {
    int garbage = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        garbage += 2;
    int result = 0;
    int max = strlen(s)-2;
    for (int i=(0+garbage); i<=max; i++) {
        char c = tolower(s[i]);
        int h;
        switch (c) {
            case 'a':
                h = 10;
                break;
            case 'b':
                h = 11;
                break;
            case 'c':
                h = 12;
                break;
            case 'd':
                h = 13;
                break;
            case 'e':
                h = 14;
                break;
            case 'f':
                h = 15;
                break;
            default:
                h = (s[i] - '0');
                break;
        }
        result += pow(16, (max-i)) * h;
    }
    return result;
}

int get_line(char s[], int lim)
{
    char c;
    int i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
