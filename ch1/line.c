#include <stdio.h>
#define MAXLEN 1000
#define IN 1
#define OUT 0

int   ft_index(char *str);
int   ft_getline(char *str, int len);

int main(void)
{
  char buffer[MAXLEN];
  int len;

  while ((len = ft_getline(buffer, MAXLEN)) > 0)
  {
    printf("%s\n", buffer);
  }
  return (0);
}

int   ft_index(char *str)
{
  int i, pos;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
    {
      pos = i;
    }
    i++;
  }
  return (pos);
}

int   ft_getline(char *str, int len)
{
  int c, i, pos;

  for (i = 0; i < len - 1 && (c = getchar()) != '\n' && c != EOF; i++)
  {
    str[i] = c;
  }
  if (c == '\n')
  {
    str[i] = c;
    i++;
  }
  str[i] = '\0';
  pos = ft_index(str);
  if (i > 1)
  {
    str[pos + 1] = '\n';
    str[pos + 2] = '\0';
  }
  if (i > 0)
  {
    return (i);
  }
  else
  {
    return (0);
  }
}
