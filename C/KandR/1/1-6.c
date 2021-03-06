#include <stdio.h>

int main()
{
  int c;
  while ((c = getchar()) != "end") {
    if (c != EOF)
      printf("not EOF\t%d\n", (c = getchar()) != EOF);
    else
      printf("EOF\t%d\n", EOF);
    printf("wainting for input\n");
  }
}
