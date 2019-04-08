#include <stdio.h>
#define abs(x) ((x) > 0 ? -(x) : (x))

int  ft_len(char *s)
{
  int i = 0;
  while (s[i] != '\0')
  {
    i++;
  }
  return (i);
}

void ft_reverse(char *str)
{
  int c, i , j;
  for (i = 0, j = ft_len(str) - 1; i < j; i++, j--)
  {
    c = str[i];
    str[i] = str[j];
    str[j] = c;
  }
}

void ft_itoa(int num, char *dst)
{
  int i, sign;

  i = 0;
  sign = num;
  do
  {
    dst[i++] = abs(num % 10) + 48;
  }while ((num /= 10) != 0);
  if (sign < 0)
  {
    dst[i++] = '-';
  }
  dst[i] = '\0';
  ft_reverse(dst);
}

int main(void)
{
  int num = -2147483648;
  printf("%d\n", num);
  char s[50];
  ft_itoa(num, s);
  printf("%s\n", s);
  return (0);
}
