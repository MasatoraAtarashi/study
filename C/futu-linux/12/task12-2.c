#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

struct cmd {
    char **argv;
    long argc;
};

void init_deamon(void);
struct cmd* parse_cmd(char *buf);
void exec_cmd(struct cmd *cmd);

int
main(int argc, char *argv[])
{
    init_deamon();
}

#define BUFSIZE 2048
void init_deamon(void)
{
    for (;;) {
        fprintf(stdout, "$ ");
        char buf[BUFSIZE];
        if (fgets(buf, BUFSIZE, stdin) == NULL) {
            exit(0);
        }
        struct cmd *cmd;
        cmd = parse_cmd(buf);
        exec_cmd(cmd);
    }
}

struct cmd* parse_cmd(char *buf)
{
    if (strcmp(buf, "quit\n") == 0 || strcmp(buf, "q\n") == 0) {
        exit(0);
    }
    struct cmd *cmd;
    cmd = malloc(sizeof(struct cmd));
    cmd->argv = malloc(BUFSIZE);
    cmd->argc = 0;

    while (*buf) {
        while (*buf && isspace((int) *buf)) {
            *buf++ = '\0';
        }
        if (*buf) {
            cmd->argv = realloc(cmd->argv, BUFSIZE*2);
            cmd->argv[cmd->argc] = buf;
            cmd->argc++;
        }
        while (*buf && !isspace((int) *buf)) {
            buf++;
        }
    }
    cmd->argv[cmd->argc] = NULL;
    return cmd;
}

void exec_cmd(struct cmd *cmd)
{
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "ERROR: %s", cmd->argv[0]);
        exit(1);
    }
    if (pid == 0) { /* child */
        execvp(cmd->argv[0], cmd->argv);
        exit(1);
    } else { /* parent */
        waitpid(pid, NULL, 0);
    }
}
