#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error");
        return 0.0;
    }
}
