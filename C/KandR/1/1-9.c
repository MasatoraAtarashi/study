#include <stdio.h>

int main()
{
  int c, before;

  while((c = getchar()) != EOF){
    if (c == ' ' && before == ' ')
      continue;
    before = c;
    putchar(c);
  }
}
