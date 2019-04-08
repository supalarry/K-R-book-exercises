#include <stdio.h>
#include <ctype.h>
#define SIZE 50

int ft_getfloat(float *f)
{
  int c, sign, power;

  power = 1;

  while ((c = getchar()) == ' ' || c == '\t');
  if (c != '+' && c != '-' && c != EOF && c != '.' && !isdigit(c))
  {
    return (0);
  }
  sign = (c == '-' ? -1 : 1);
  if (c == '+' || c == '-')
  {
    c = getchar();
  }
  while (c != '.')
  {
    if (isdigit(c))
    {
      *f = *f * 10 + (c - 48);
      c = getchar();  
    }
  }
  if (c == '.')
  {
    c = getchar();
  }
  while (c != '\n' && c != EOF)
  {
    *f = *f * 10 + (c - 48);
    power *= 10;
    c = getchar();
  }
  *f /= power;
  *f *= sign;
  return (*f);
}

int main(void)
{
  int i;
  float buffer[SIZE];

  for (i = 0; i < SIZE && ft_getfloat(&buffer[i]); i++);
  printf("%.2f\n", buffer[0]);
  printf("%.2f\n", buffer[1]);
  return (0);
}
