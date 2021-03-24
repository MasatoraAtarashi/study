#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <getopt.h>

static struct option longopts[] = {
        {"lines", required_argument, NULL, 'n'},
        {0, 0,0, 0}
};

#define DEFAULT_N_LINES 5

static void do_tail(FILE *f, int nlines);

int
main(int argc, char *argv[])
{
    int nlines, opt;
    while ((opt = getopt_long(argc, argv, "n:", longopts, NULL)) != -1) {
        switch (opt) {
            case 'n':
                nlines = atoi(optarg);
                break;
            case '?':
                fprintf(stderr, "Error: %s", argv[0]);
                exit(1);
        }
    }

    if (argc == optind) {
        do_tail(stdin, nlines);
    } else {
        int i;
        for (i = optind; i < argc; i++) {
            FILE *f;
            f = fopen(argv[i], "r");
            if (!f) {
                perror(argv[1]);
                exit(1);
            } else {
                do_tail(f, nlines);
                fclose(f);
            }
        }
    }

}

#define BUFFER_SIZE 2048
#define MAX_LINE 1000
static void
do_tail(FILE *f, int nlines)
{
    if (!(nlines)) nlines = DEFAULT_N_LINES;
    int n = 0;
    char lines[MAX_LINE][BUFFER_SIZE];
    while (fgets(lines[n], sizeof lines[n], f) != NULL) {
        n++;
    }
    int i;
    i = (nlines > n ? 0 : n - nlines);
    for (; i <= n; i++) {
        printf("%s", lines[i]);
    }
}
