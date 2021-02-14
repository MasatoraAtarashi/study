#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1024

void expand(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE], s2[MAXLINE];
    strcpy(s1, "-a-z0-9-");
    expand(s1, s2);
    return 0;
}

void expand(char s1[], char s2[]) {
    int i, j;
    for (i=j=0; i<strlen(s1); i++) {
        if (s1[i] == '-' && s1[i-1] <= s1[i+1] && i != 0 && i != strlen(s1)) {
            j--;
            for (char c=s1[i-1]; c<=s1[i+1]; c++) {
                s2[j++] = c;
            }
            i++;
        } else {
            s2[j++] = s1[i];
        }
    }
    printf("result: %s\n", s2);
}
