#include <stdio.h>
#define MAX 1000

int   ft_getline(char *str, int max);
int   ft_verify(char *buffer, char *buf, char *phrase);
int   ft_strcmp(char *one, char *two);
int   ft_len(char *s);
int   ft_verify2(char *line, char *phrase);
void  ft_copy(char *src, char *dst, int start, int end);
void  ft_copy2(char *src, char *dst);
int ft_strrindex(char *line, char *phrase);

int pos = 0;

int main(void)
{
  //char  buf[MAX];
  /*char  buffer[MAX];
  char  container[MAX];
  char  phrase[] = "ould";
  while (ft_getline(buffer, MAX) == 1)
  {
    if (ft_verify2(buffer, phrase) == 1)
    {
      ft_copy2(buffer, container);
    }
  }
  container[pos] = '\0';
  printf("\n%s\n", container);*/
  printf("%d\n", ft_strrindex("I want cake", "ake"));
}

int ft_strrindex(char *line, char *phrase)
{
  // we have to create additional variable of pos, and each times
  // we find a match we save the i or the starting position
  // in the end we return the position and initialize pos to -1
  // -1 for no matches essentially
  int i, j, k, pos;

  pos = -1;
  for (i = 0; line[i] != '\0'; i++)
  {
    for (j = i, k = 0; phrase[k] != '\0' && line[j] == phrase[k]; k++, j++);
    if (phrase[k] == '\0')
    {
      pos = i;
    }
  }
  return (pos);
}

int ft_verify2(char *line, char *phrase)
{
  int i, j, k;

  for (i = 0; line[i] != '\0'; i++)
  {
    for (j = i, k = 0; phrase[k] != '\0' && phrase[k] == line[j]; j++, k++)
      ;
    if (k > 0 && phrase[k] == '\0')
    {
      return (1);
    }
  }
  return (0);
}

int ft_verify(char *buffer, char *buf, char *phrase)
{
  int i, len, found;

  len = ft_len(phrase);
  i = found = 0;

  while (buffer[i] != '\0')
  {
    ft_copy(buffer, buf, i, i + len);
    if (ft_strcmp(buf, phrase) == 0)
    {
      return (1);
    }
    i++;
  }
  return (0);
}

void ft_copy(char *src, char *dst, int start, int end)
{
  int i = 0;
  while (start < end)
  {
    dst[i] = src[start];
    start++;
    i++;
  }
  dst[i] = '\0';
}

void ft_copy2(char *src, char *dst)
{
  int i = 0;
  while (src[i] != '\0')
  {
    dst[pos] = src[i];
    pos++;
    i++;
  }
  dst[pos++] = '\n';
}

int  ft_len(char *s)
{
  int i = 0;
  while (s[i] != '\0')
  {
    i++;
  }
  return (i);
}

int ft_strcmp(char *one, char *two)
{
  int i = 0;
  while (one[i] == two[i] && one[i] != '\0' && two[i] != '\0')
  {
    i++;
  }
  return (one[i] - two[i]);
}

int ft_getline(char *str, int max)
{
  int i, c;

  i = 0;
  while (i < max - 1 && (c = getchar()) != '\n' && c != EOF)
  {
    str[i] = c;
    i++;
  }
  if (c == '\n')
  {
    str[i++] = '\n';
  }
  str[i] = '\0';
  if (i != 0)
  {
    return (1);
  }
  else
  {
    return (0);
  }
}
