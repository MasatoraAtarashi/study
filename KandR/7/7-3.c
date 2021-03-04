#include <stdarg.h>
#include <stdio.h>

void mini_print(char *, ...);

int main() {
    int a = 1;
    mini_print("d: %d\nf: %f\ns: %s\nc: %c\np: %p\nparcent: %%\n", 3, 3.0, "aiueo", 'a', &a);
    return 0;
}

void mini_print(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    char cval;
    int *pval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'c':
                cval = va_arg(ap, int);
                printf("%c", cval);
                break;
            case 'p':
                pval = va_arg(ap, int*);
                printf("%p", pval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}
