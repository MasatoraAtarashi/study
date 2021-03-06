#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[1024];
    strcpy(s1, "masatoraatarashi");
    squeeze(s1, "aiueo");
    return 0;
}

void squeeze(char s1[], char s2[]) {
    for (int i=0; i<strlen(s2); i++) {
        char c = s2[i];
        int j,k;
        for (j=k=0; j<strlen(s1); j++) {
            if (s1[j] != c) {
               s1[k++] = s1[j];
            }
        }
        s1[k] = '\0';
    }
    printf("result: %s\n", s1);
}
