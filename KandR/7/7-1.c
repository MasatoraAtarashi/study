#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c;
    if (argc > 1) {
        while ((c = getchar()) != EOF)
            if (strcmp(argv[1], "a")) {
                putchar(tolower(c));
            } else {
                putchar(toupper(c));
            }
    }
    return 0;
}
