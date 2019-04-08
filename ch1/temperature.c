#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void)
{
  printf("Celsius to Fahrenheit converter\n");

  /*int start = 0;
  int step = 20;
  int end = 100;

  float celsius = start;
  while (celsius <= end)
  {
    float fahrenheit = (celsius * (9.0 / 5.0) + 32);
    printf("%3.0f %6.0f\n", celsius, fahrenheit);
    celsius = celsius + 20;
  }*/
  for (int fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
  {
    printf("%3d %6.1f\n", fahr, (5.0/9.0 * (fahr - 32)));
  }
  /*
  FAHR -> CELSIUS
  for (int i = 0; i <= 300; i = i + 20)
  {
    printf("%i\t%i\n", i, (5 * (i - 32)) / 9);
  }
  int lower = 0;
  int step = 20;
  int upper = 300;


  while (lower <= upper)
  {
    printf("%3i %6.1f\n", lower, (5.0 / 9.0 * (lower - 32)));
    lower = lower + step;
  }
  */
}
