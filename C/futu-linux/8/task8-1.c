#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>
#define _GNU_SOURCE
#include <getopt.h>

static void do_grep(regex_t *pat, FILE *f, int invert_match);

static struct option longopts[] = {
        {"ignore-case", no_argument, NULL, 'i'},
        {"invert-match", no_argument, NULL, 'v'},
        {0, 0,0, 0}
};

int
main(int argc, char *argv[])
{
    int ignore_case, invert_match, opt;
    while ((opt = getopt_long(argc, argv, "iv", longopts, NULL)) != -1) {
        switch (opt) {
            case 'i':
                ignore_case = 1;
                break;
            case 'v':
                invert_match = 1;
                break;
            case '?':
                fprintf(stderr, "Error: %s", argv[0]);
                exit(1);
        }
    }

    regex_t pat;
    int err;
    int i;

    if (argc < 2) {
        fputs("no pattern\n", stderr);
        exit(1);
    }
    if (ignore_case) {
        err = regcomp(&pat, argv[optind], REG_ICASE);
    } else {
        err = regcomp(&pat, argv[optind], REG_EXTENDED | REG_NOSUB | REG_NEWLINE);
    }
    if (err != 0) {
        char buf[1024];

        regerror(err, &pat, buf, sizeof buf);
        puts(buf);
        exit(1);
    }
    if (argc == optind) {
        fprintf(stderr, "Error: %s\n", argv[0]);
        exit(1);
    } else if (argc == (optind+1)) {
        do_grep(&pat, stdin, invert_match);
    }
    else {
        for (i = optind+1; i < argc; i++) {
            FILE *f;

            f = fopen(argv[i], "r");
            if (!f) {
                perror(argv[i]);
                exit(1);
            }
            do_grep(&pat, f, invert_match);
            fclose(f);
        }
    }
    regfree(&pat);
    exit(0);
}

static void
do_grep(regex_t *pat, FILE *src, int invert_match)
{
    char buf[4096];

    while (fgets(buf, sizeof buf, src)) {
        int f = regexec(pat, buf, 0, NULL, 0);
        if (invert_match) {
            if (f != 0) fputs(buf, stdout);
        } else {
            if (f == 0) fputs(buf, stdout);
        }
    }
}
