#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
  int i = htoi("CA125");
  printf("%d\n", i);
  return 0;
}

int htoi(char s[]) {
  //if (s[0] == "0" && (s[1] == "x" || s[1] == "X")
  int result = 0;
  for (int i=0; i<strlen(s); i++) {
    char c = tolower(s[i]);
    int h;
    switch (c) {
      case 'a':
        h = 10;
        break;
      case 'b':
        h = 11;
        break;
      case 'c':
        h = 12;
        break;
      case 'd':
        h = 13;
        break;
      case 'e':
        h = 14;
        break;
      case 'f':
        h = 15;
        break;
      default:
        h = (int)c;
        break;
    }
    printf
    result += pow(16, i) * h;
  }
  return result;
}
