#include <stdio.h>
#define MAX 1000
#define TABSTOP 4

int ft_spaces(char *str, int pos);
int ft_end(char *str, int pos);
int  ft_getline(char *str, int max);
void ft_entab(char *src, char *dst);

int main(void)
{
  int len;
  char line[MAX];
  char transfer[MAX];

  while ((len = ft_getline(line, MAX)) > 0)
  {
    ft_entab(line, transfer);
    printf("%s\n", transfer);
  }
}

void ft_entab(char *src, char *dst)
{
  int i, pos, spaces, end, aftermath, multiple, j;

  i = pos = multiple = 0;
  while (src[i] != '\0')
  {
    if (src[i] == ' ') // i is starting index of spaces
    {
      spaces = ft_spaces(src, i); // how many spaces
      end = ft_end(src, i); // index of last space
      j = i;
      if (i == 0 && (end + 1) % TABSTOP == 0)
      {
        end++;
      }
      while (i < end)
      {
        if ((i + 1) % TABSTOP == 0)
        {
          dst[pos] = '\t';
          multiple = i;
          pos++;
        }
        i++;
      }
      if (multiple == 0)
      {
        aftermath = end - j;
      }
      else
      {
        aftermath = end - multiple - 1;
      }
      while (aftermath > 0)
      {
        dst[pos] = ' ';
        pos++;
        aftermath--;
      }
    }
    else
    {
      dst[pos] = src[i];
      pos++;
      i++;
    }
    multiple = 0;
  }
  dst[pos] = '\0';
}

int ft_spaces(char *str, int pos)
{
  int counter = 0;
  while (str[pos] == ' ')
  {
    counter++;
    pos++;
  }
  return (counter);
}

int ft_end(char *str, int pos)
{
  while (str[pos] == ' ')
  {
    pos++;
  }
  return (pos);
}

int ft_getline(char *str, int max)
{
  int i, c;

  for (i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; i++)
  {
    str[i] = c;
  }
  if (c == '\n')
  {
    str[i] = c;
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
