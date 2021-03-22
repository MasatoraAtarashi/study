#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

static void die(const char *s);

int
main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++) {
        FILE *f;

        f = fopen(argv[i], "r");
        if (!f) die(argv[i]);

        unsigned char buf[BUFFER_SIZE];
        for (;;) {
            size_t n_read = fread(buf, 1, sizeof buf, f);
            if (ferror(f)) die(argv[i]);
            size_t n_write = fwrite(buf, 1, sizeof buf, stdout);
            if (n_write < n_read) die(argv[i]);
            if (n_read < sizeof buf) break;
        }

        if (fclose(f) != 0) die(argv[i]);
    }
}

static void
die(const char *s)
{
    perror(s);
    exit(1);
}

