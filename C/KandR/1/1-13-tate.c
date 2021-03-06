#include <stdio.h>

#define MAXCNT 10
#define IN 1
#define OUT 0

int main()
{
  int c;
  int wc = 0;
  int state = OUT;
  int num_each_wc[MAXCNT];
  for (int i = 0; i < MAXCNT; ++i)
    num_each_wc[i] = 0;
  while((c = getchar()) != EOF){
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN)
        ++num_each_wc[wc - 1];
        wc = 0;
      state = OUT;
    } else {
      state = IN;
      ++wc;
    }
  }
  for (int i = MAXCNT; i > 0; --i) {
    for (int j = 0; j < MAXCNT; ++j) {
      if (num_each_wc[j] >= i)
        printf("|");
      else
        printf(" ");
    }
    printf("\n");
  }
  printf("12345678910\n");

  return 0;
}
