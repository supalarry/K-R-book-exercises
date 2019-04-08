#include <stdio.h>
#define MAX 50

int     ft_getline(char *source, int max);
double  ft_atof(char *source);

int main(void)
{
  char source[MAX];
  while (ft_getline(source,MAX) == 1)
  {
    printf("%f\n", ft_atof(source));
  }
  return (0); 
}

double  ft_atof(char *source)
{
  double  res, power;
  int     i, sign;

  res = 0.0;
  power = 1.0;
  i = sign = 0;
  for ( ; source[i] == ' ' || source[i] == '\t'; i++);
  sign = (source[i] == '-' ? -1 : 1);
  for ( ; source[i] == '-' || source[i] == '+'; i++);
  while (source[i] != '.')
  {
    res = res * 10.0 + (source[i] - 48);
    i++;
  }
  i++;
  while (source[i] != '\n' && source[i] != 'e' && source[i] != 'E')
  {
    res = res * 10.0 + (source[i] - 48);
    i++;
    power *= 10;
  }
  printf("%f\n", res);
  if (source[i] == 'e' || source[i] == 'E')
  {
    if (source[i + 1] == '-')
    {
      //printf("%c\n", source[i + 2]);
      int extra = source[i + 2] - 48;
      while (extra > 0)
      {
        power *= 10;
        extra--;
      }
      return (res * sign / power);
    }
    else if (source [i + 1] == '+')
    {
      int extra = source[i + 2] - 48;
      while (extra > 0)
      {
        power /= 10;
        extra--;
      }
      return (res * sign / power);
    }
  }
  else
  {
    return (res * sign / power);
  }
}

int ft_getline(char *source, int max)
{
  int i, c;

  i = 0;
  for ( ; i < max - 1 && (c = getchar()) != '\n' && c != EOF; i++)
  {
    source[i] = c;
  }
  if (c == '\n')
  {
    source[i++] = c;
  }
  source[i] = '\0';
  return (i > 0 ? 1 : -1);
}
