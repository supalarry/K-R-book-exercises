#include <stdio.h>

int ft_is(char x, char *str)
{
  int i = 0;

  while (str[i] != '\0')
  {
    if (str[i] == x)
    {
      return (1);
    }
    i++;
  }
  return (0);
}

int ft_any(char *original, char *restricted)
{
  int i = 0;

  while (original[i] != '\0')
  {
    if (ft_is(original[i], restricted) != 0)
    {
      return (i);
    }
    i++;
  }
  return (-1);
}

int main(void)
{
  char word1[] = "skrub";
  char word2[] = "bxxxb";
  printf("%d\n", ft_any(word1, word2));
}
