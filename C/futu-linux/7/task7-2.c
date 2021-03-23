#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_N_LINES 5

static void do_tail(FILE *f);

int
main(int argc, char *argv[])
{
    if (argc == 1) {
        do_tail(stdin);
    } else {
        int i;
        for (i = 1; i < argc; i++) {
            FILE *f;
            f = fopen(argv[i], "r");
            if (!f) {
                perror(argv[1]);
                exit(1);
            } else {
                do_tail(f);
                fclose(f);
            }
        }
    }

}

#define BUFFER_SIZE 2048
#define MAX_LINE 1000
static void
do_tail(FILE *f)
{
    int nline = 0;
    char lines[MAX_LINE][BUFFER_SIZE];
    while (fgets(lines[nline], sizeof lines[nline], f) != NULL) {
        nline++;
    }
    int i;
    i = (DEFAULT_N_LINES > nline ? 0 : nline - DEFAULT_N_LINES);
    for (; i <= nline; i++) {
        printf("%s", lines[i]);
    }
}
