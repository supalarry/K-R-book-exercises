#include <stdio.h>
#define abs(x) ((x) < 0 ? -(x) : x)

int  ft_len(char *s)
{
  int i = 0;
  while (s[i] != '\0')
  {
    i++;
  }
  return (i);
}

void ft_itoa(int num, char *dst, int len)
{
  int i, sign;

  i = 0;
  sign = num;

  do
  {
    dst[i++] = abs(num % 10) + '0';
  }while((num = num / 10) > 0);
  if (sign < 0)
  {
    dst[i++] = '-';
  }
  while (i < len)
  {
    dst[i++] = ' ';
  }
  dst[i] = '\0';
  int j, k, c;
  for (j = 0, k = ft_len(dst) - 1; j < k; j++, k--)
  {
    c = dst[j];
    dst[j] = dst[k];
    dst[k] = c;
  }
}
int main(void)
{
  char dst[64];
  int num = 422;
  int len = 5;
  ft_itoa(num, dst, len);
  printf("%s\n", dst);
}
