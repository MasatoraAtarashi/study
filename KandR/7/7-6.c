#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

// diff
int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char c1[MAXLINE], c2[MAXLINE];

    if (argc == 3) {
        if ((fp1 = fopen(*++argv, "r")) == NULL || ((fp2 = fopen(*++argv, "r")) == NULL)) {
            printf("Error: cant open file\n");
            return 1;
        } else {
            do {
                fgets(c1, MAXLINE, fp1);
                fgets(c2, MAXLINE, fp2);
            } while (strcmp(c1, c2) == 0);
            printf("%s---\n%s", c1, c2);
            fclose(fp1);
            fclose(fp2);
        }
    } else {
        printf("Error: invalid arguments\n");
    }
}
