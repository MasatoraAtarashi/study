#include <stdio.h>

/* count up \s, \t, \n */
int main()
{
  int c, ns, nt, nn;
  ns = nt = nn = 0;

  while((c = getchar()) != EOF){
    if (c == ' ')
      ++ns;
    else if (c == '\t')
      ++nt;
    else if (c == '\n')
      ++nn;
  }
  printf("%d %d %d\n", ns, nt, nn);
}
