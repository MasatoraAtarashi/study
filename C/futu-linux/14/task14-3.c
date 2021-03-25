#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <pwd.h>

static void do_ls(char *path);
static void print_file_info(struct dirent *ent);

int
main(int argc, char *argv[])
{
    int i;

    if (argc < 2) {
        fprintf(stderr, "%s: no arguments\n", argv[0]);
        exit(1);
    }
    for (i = 1; i < argc; i++) {
        do_ls(argv[i]);
    }
    exit(0);
}

static void
do_ls(char *path)
{
    DIR *d;
    struct dirent *ent;

    d = opendir(path);
    if (!d) {
        perror(path);
        exit(1);
    }
    while ((ent = readdir(d))) {
        if (*ent->d_name == '.') {
            continue;
        } else if (ent->d_type == DT_DIR) {
            strcat(path, "/");
            strcat(path, ent->d_name);
            do_ls(path);
        }
        print_file_info(ent);
    }
    closedir(d);
}

static void
print_file_info(struct dirent *ent)
{
    struct stat *buf;
    buf = malloc(sizeof(struct stat));
    if ((stat(ent->d_name, buf)) < 0) {
        fprintf(stderr, "ERROR");
        exit(1);
    }

    struct passwd *passwd = getpwuid(buf->st_uid);
    char *time_buf;
    time_buf = malloc(1024);
    struct tm *time = localtime(&(buf->st_ctimespec.tv_sec));
    strftime(time_buf, 1024, "%b %e %R", time);
    printf("%s ", passwd->pw_name);
    printf("%s ", time_buf);
    printf("%s\n", ent->d_name);

    free(buf);
    free(time_buf);
}
