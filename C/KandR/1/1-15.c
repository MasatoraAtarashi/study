#include <stdio.h>
float conversion(float f);

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = conversion(fahr);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

float conversion(float fahr) {
  float celsius = 5 * (fahr-32) / 9;
  return celsius;
}

