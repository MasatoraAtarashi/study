#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <getopt.h>

static void do_cat(FILE *f, int debug);

static struct option longopts[] = {
        {"debug", no_argument, NULL, 'd'},
        {0, 0,0, 0}
};

int
main(int argc, char *argv[])
{
    int debug, opt;
    while ((opt = getopt_long(argc, argv, "d", longopts, NULL)) != -1) {
        switch (opt) {
            case 'd':
                debug = 1;
                break;
            case '?':
                fprintf(stderr, "Error: %s", argv[0]);
                exit(1);
        }
    }

    if (optind == argc) {
        do_cat(stdin, debug);
    } else {
        int i;
        for (i = optind; i < argc; i++) {
            FILE *f;
            f = fopen(argv[i], "r");
            if (!f) {
                perror(argv[1]);
                exit(1);
            } else {
                do_cat(f, debug);
                fclose(f);
            }
        }
    }

}

static void
do_cat(FILE *f, int debug)
{
    int c;
    while ((c = fgetc(f)) != EOF) {
        if (debug) {
            if (c == '\t') {
                if (putchar('\\') < 0) exit(1);
                if (putchar('t') < 0) exit(1);
            } else if (c == '\n') {
                if (putchar('$') < 0) exit(1);
                if (putchar('\n') < 0) exit(1);
            } else {
                if (putchar(c) < 0) exit(1);
            }
        } else {
            if (putchar(c) < 0) exit(1);
        }
    }
}
