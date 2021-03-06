#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];

    argv++;
    while (--argc > 0) {
        if (isdigit(*argv[0])) {
            push(atof(*argv));
        } else {
            switch (*argv[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    push(pop() / op2);
                    break;
                default:
                    printf("error\n");
                    break;
            }
        }
        argv++;
    }
    printf("result: %f\n", pop());
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error\n");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error\n");
        return 0.0;
    }
}
