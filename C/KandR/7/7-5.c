#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main()
{
    int type;
    double num, op2;
    char s[MAXOP], c, sep;

    while (scanf("%s%c", s, &sep) == 2) {
        if (sscanf(s, "%lf", &num) == 1) {
            push(num);
        } else if (sscanf(s, "%c", &c) == 1){
            switch (c) {
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
        if (sep == '\n')
            printf("result: %f\n", pop());
    }
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
