#include <stdio.h>
#define MAXLEN 1000

int   ft_strlen(char *str);
void  ft_reverse(char *str);
int   ft_getline(char *str, int len);

int   main(void)
{
  char buffer[MAXLEN];
  int len;

  while ((len = ft_getline(buffer, MAXLEN)) > 0)
  {
    ft_reverse(buffer);
    printf("%s\n", buffer);
  }
  return (0);
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

void  ft_reverse(char *str)
{
  int len, i, times;
  char temp;

  i = 0;
  len = ft_strlen(str);
  times = len / 2;
  while (times > 0)
  {
    temp = str[i];
    len = len - 1;
    str[i] = str[len];
    str[len] = temp;
    i++;
    times = times - 1;
  }
}

int   ft_getline(char *str, int len)
{
  int i, c;

  for (i = 0; i < len - 1 && (c = getchar()) != '\n' && c != EOF; i++)
  {
    str[i] = c;
  }
  if (c == '\n')
  {
    str[i] = '\n';
    i++;
  }
  str[i] = '\0';
  if (i > 0)
  {
    return (i);
  }
  else
  {
    return (0);
  }
}
