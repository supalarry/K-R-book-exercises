#include <stdio.h>

int ft_len(char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  return (i - 1);
}

void ft_rev(char *str)
{
  int i, j;

  for (i = 0, j = ft_len(str) - 1; i < j; i++, j--)
  {
    int temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

void ft_reverse(char *str)
{
  static int start = 0;
  int end = ft_len(str) - start;

  if (start < end)
  {
    int temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    ft_reverse(str);
  }
}

int main(void)
{
  char buffer[] = "damn";
  ft_reverse(buffer);
  printf("%s\n", buffer);
}
