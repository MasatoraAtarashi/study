#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
int remove_space_from_eol(char line[], int i);
void printf_debug(char line[]);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
    printf_debug(line);
    printf("\n");
  return 0;
}

int get_line(char s[], int lim)
{
  int c, i;
  i = 0;

  while (i<lim-1 && (c=getchar())!=EOF) {
    if (c == ' ')
      continue;
    else
      s[i] = c;
      ++i;
    if (c == '\n')
      break;
  }
  i = remove_space_from_eol(s, i);
  s[i] = '\0';
  return i;
}

int remove_space_from_eol(char s[], int i) {
  for (i; i >= 0; --i) {
    if (s[i-2] == ' ' || s[i-2] == '\t') {
      s[i-2] = '\n';
    } else {
      break;
    }
  }
  return i;
}

void printf_debug(char s[]) {
  for (int i=0; s[i] != '\0'; ++i) {
    if (s[i] == '\t')
      printf("\\t");
    else if (s[i] == ' ')
      printf("<s>");
    else
      printf("%c", s[i]);
  }
}
