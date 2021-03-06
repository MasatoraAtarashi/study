#include <stdio.h>

/* comment
*/

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0/5.0) * celsius + 32;
    printf("%6.1f\t%3.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
