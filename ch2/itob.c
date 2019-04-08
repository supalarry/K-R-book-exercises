#include <stdio.h>

int  ft_len(char *s)
{
  int i = 0;
  while (s[i] != '\0')
  {
    i++;
  }
  return (i);
}

void ft_itob(int n, int b, char *str)
{
  int i = 0;
  char database[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
'B', 'C', 'D', 'E', 'F'};

  while (n != 0)
  {
    str[i] = n % b;
    n /= b;
    i++;
  }
  str[i] = '\0';
  int j, k, c;
  for (j = 0, k = ft_len(str) - 1; j < k; j++, k--)
  {
    c = str[j];
    str[j] = str[k];
    str[k] = c;
  }

  for (int x = 0 ; x < i; x++)
  {
    str[x] = database[str[x]];
  }
}

int main(void)
{
  char str[64];
  int num = 88;
  int base = 16;
  ft_itob(88, 16, str);
  printf("%s\n", str);
}
