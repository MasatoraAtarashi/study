#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

int
main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++) {
        FILE *f;

        f = fopen(argv[i], "r");
        if (!f) {
            perror(argv[i]);
            exit(1);
        }

        char buf[BUFFER_SIZE];
        int cnt = 0;
        while (fgets(buf, sizeof buf, f) != NULL) {
            cnt++;
        }
        printf("%s: %d\n", argv[i], cnt);
        fclose(f);
    }
}
