#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define SIZE 100

static char allocbuf[SIZE];
static char *allocp = allocbuf;

char *ft_alloc(int n)
{
  if (SIZE - (allocp - allocbuf) >= n)
  {
    allocp += n;
    return (allocp - n);
  }
  else
  {
    return (NULL);
  }
}

int ft_strlen(char *s)
{
  char *p = s;
  while (*p != '\0')
  {
    p++;
  }
  return (p - s);
}

void ft_free(int n)
{
  allocp -= n;
}

int main(void)
{
  char *start;

  start = ft_alloc(10);
  if (start != NULL)
  {
    for (int i = 0; i < 10; i++)
    {
      *start = i;
      start++;
    }
  }
}
