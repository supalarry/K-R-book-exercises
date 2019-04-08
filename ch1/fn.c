#include <stdio.h>
#define MAXLEN 1000

int ft_getline(char *arr, int len);
void ft_copy(char *dst, char *src);

int   main(void)
{
  int len, max;
  char line[MAXLEN];
  char longest[MAXLEN];

  max = 0;
  while ((len = ft_getline(line, MAXLEN)) > 0)
  {
    if (len > max)
    {
      max = len;
      ft_copy(longest, line);
    }
  }
  if (max > 0)
  {
    printf("%s\n", longest);
  }
  return (0);
}

void ft_copy(char *dst, char *src)
{
  int i = 0;
  while (src[i] != '\0')
  {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
  //printf("%s\n", dst);
}

int ft_getline(char *arr, int len)
{
  int c, i;

  for (i = 0; i < len - 1 && (c = getchar()) != '\n' && c != EOF; i++)
  {
    arr[i] = c;
  }
  if (c == '\n')
  {
    arr[i] = c;
    i++;
  }
  arr[i] = '\0';
  printf("%s\n", arr);
  return (i);
}
