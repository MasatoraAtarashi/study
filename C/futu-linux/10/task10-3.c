#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

static void do_mkdir(char *path);

int
main(int argc, char *argv[])
{
    int i;

    if (argc < 2) {
        fprintf(stderr, "%s: no arguments\n", argv[0]);
        exit(1);
    }
    for (i = 1; i < argc; i++) {
        do_mkdir(argv[i]);
    }
    exit(0);
}

static void do_mkdir(char *path)
{
    if (mkdir(path, 0777) < 0) {
        if (errno == ENOENT) {
            // 1. pathを/で分解して、最後のを削る
            int len = strlen(path);
            char copy_path[len];
            strcpy(copy_path, path);
            int i = len;
            // 最後の/に対応
            if (!(strcmp((path+(--i)), "/"))) {
                i--;
            }
            while (copy_path[--i] != '/')
                ;
            copy_path[i] = '\0';

            // 2. 削ったpathでmkdir
            do_mkdir(copy_path);

            // 3. 削る前のpathでmkdir
            do_mkdir(path);
        } else {
            perror(path);
            exit(1);
        }
    }
}
