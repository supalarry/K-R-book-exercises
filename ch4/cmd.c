#include <stdio.h>
#define MAXLINE 100

int ft_getline(char *buffer, int maxlen);
int ft_check(char *buffer, char *pattern);
int ft_strcmp(char *start, char *pattern);

int main(int argc, char **argv)
{
  char  buffer[MAXLINE];
  int   c, number, reverse, exit, linen;

  number = reverse = exit = linen = 0;
  while (--argc > 0 && (*++argv)[0] == '-')
  {
    while (c = *(*argv++))
    {
      switch(c)
      {
        case 'x':
          reverse = 1;
          break;
        case 'n':
          number = 1;
          break;
        default:
          printf("Illegal option\n");
          exit = 1;
          break;
      }
    }
  }
  if (argc != 1)
  {
    printf("Usage: ./cmd pattern\n");
    return (0);
  }
  else
  {
    while (ft_getline(buffer, MAXLINE) > 0)
    {
      linen++;
      if (ft_check(buffer, *argv) != reverse)
      {
        if (number)
        {
          printf("%d: ", linen);
        }
        printf("%s\n", buffer);
      }
    }
  }
  printf("\n");
  return (0);
}

int ft_strcmp(char *start, char *pattern)
{
  int i = 0;
  while (start[i] == pattern[i])
  {
    i++;
  }
  if (pattern[i] == '\0')
  {
    return (1);
  }
  return (0);
}

int ft_check(char *buffer, char *pattern)
{
  int i = 0;
  while (buffer[i] != '\0')
  {
    if (ft_strcmp(&buffer[i], pattern))
    {
      return (1);
    }
    i++;
  }
  return (0);
}

int ft_getline(char *buffer, int maxlen)
{
  int i, c;

  for (i = 0; i < maxlen && (c = getchar()) != '\n' && c != EOF; i++)
  {
    buffer[i] = c;
  }
  if (c == '\n')
  {
    buffer[i++] = c;
  }
  buffer[i] = '\0';
  return (i - 1);
}
