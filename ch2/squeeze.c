#include <stdio.h>

int  ft_not(char x, char *str)
{
  int i, found;

  i = found = 0;
  while (str[i] != '\0')
  {
    if (str[i] == x)
    {
      found = 1;
      break;
    }
    i++;
  }
  return (found);
}

void ft_squeeze(char *original, char *restricted)
{
  int i, j;

  i = j = 0;
  while (original[i] != '\0')
  {
    if (ft_not(original[i], restricted) == 0)
    {
      original[j] = original[i];
      j++;
    }
    i++;
  }
  original[j] = '\0';
}

/*void squeeze(char *arr, char x)
{
  int i, j;

  i = j = 0;
  while (arr[i] != '\0')
  {
    if (arr[i] != x)
    {
      arr[j] = arr[i];
      j++;
    }
    i++;
  }
  arr[j] = '\0';
}*/

int main(void)
{
  char word1[] = "abcdefg";
  char word2[] = "bdf";
  ft_squeeze(word1, word2);
  printf("%s\n", word1);
}
