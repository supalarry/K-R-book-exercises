#include <stdio.h>
#define MAX 100
#include <stdlib.h>

int     ft_getline(char *buffer, int len);
double  ft_atof(char *buffer);

int main(void)
{
  char    buffer[MAX];
  double  sum = 0.0;
  while (ft_getline(buffer, MAX) == 1)
  {
    sum += ft_atof(buffer);
    printf("%.2f\n", sum);
  }
  return (0);
}

double ft_atof(char *buffer)
{
  double val, power;
  int    i, sign;

  val = 0.0;
  power = 1.0;
  i = 0;
  for ( ; buffer[i] == ' ' || buffer[i] == '\t'; i++);
  sign = (buffer[i] == '-' ? -1 : 1);
  for ( ; buffer[i] == '+' || buffer[i] == '-'; i++);
  while (buffer[i] != '.')
  {
    val = val * 10.0 + (buffer[i] - 48);
    i++;
  }
  i++;
  while (buffer[i] != '\n')
  {
    val = val * 10.0 + (buffer[i] - 48);
    i++;
    power *= 10;
  }
  return (val * sign / power);
}

int ft_getline(char *str, int max)
{
  int i, c;

  for (i = 0 ; i < max - 1 && (c = getchar()) != '\n' && c != EOF; i++)
  {
    str[i] = c;
  }
  if (c == '\n')
  {
    str[i] = c;
    i++;
  }
  str[i] = '\0';
  return (i > 0 ? 1 : 0);
}
