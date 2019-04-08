#include <stdio.h>

int   number(int letter);
int   ft_strlen(char *str);
int   ft_power(int pow);
int   htoi(char *str);


int main(void)
{
  printf("%d\n", htoi("0X397"));
  return (0);
}

int number(int letter)
{
  switch (letter)
  {
    case 'A' : return 10;
    case 'a' : return 10;
    case 'B' : return 11;
    case 'b' : return 11;
    case 'C' : return 12;
    case 'c' : return 12;
    case 'D' : return 13;
    case 'd' : return 13;
    case 'E' : return 14;
    case 'e' : return 14;
    case 'F' : return 15;
    case 'f' : return 15;
    default  : return 0;
  }
}

int   ft_strlen(char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  return (i);
}

int   ft_power(int pow)
{
  int res = 1;
  if (pow == 0)
  {
    return (1);
  }
  while (pow > 0)
  {
    res = res * 16;
    pow--;
  }
  return (res);
}

int   htoi(char *str)
{
  int i, res, pow, num;

  i = res = 0;

  pow = ft_strlen(str) - 1;

  if (str[i] == '0' && (str[i+1] == 'x' || str[i+1] == 'X'))
  {
    i = i + 2; // jump over 0x
    pow = pow - 2;
  }
  while (str[i] != '\0')
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      res = res + ((str[i] - '0') * ft_power(pow));
    }
    else
    {
      num = number(str[i]);
      res = res + (num * ft_power(pow));
    }
    pow--;
    i++;
  }
  return (res);
}
