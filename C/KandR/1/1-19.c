#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char line[], int len);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
    printf("%s\n", line);
  return 0;
}

int get_line(char s[], int lim)
{
  int c, i;
  i = 0;

  while (i<lim-1 && (c=getchar())!=EOF) {
    if (c == '\n') {
      reverse(s, i);
      break;
    }
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void reverse(char s[], int len) {
  --len;
  char new_line[len];

  for (int i=0; i<=len; ++i)
    new_line[i] = s[len-i];
  
  for (int i=0; i<=len; ++i)
    s[i] = new_line[i];
}
