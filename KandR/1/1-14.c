#include <stdio.h>
#define MAXINT 1000

void set_num_each_words();
void hist(int a[MAXINT]);

int num_each_words[MAXINT];

int main()
{
  int c;
  
  set_num_each_words();

  while((c = getchar()) != EOF){
    if (!(c == ' ' || c == '\n' || c == '\t'))
      num_each_words[c]++;
  }
  
  hist(num_each_words);

  return 0;
}

void set_num_each_words() {
  for (int i = 0; i < MAXINT; i++)
    num_each_words[i] = 0;
}

void hist(int array[MAXINT]) {
  for (int i = 0; i < MAXINT; i++) {
    if (array[i] == 0)
      continue;
    putchar(i);
    for (int j = 0; j < array[i]; j++)
      printf("-");
    printf("\n");
  }
}
