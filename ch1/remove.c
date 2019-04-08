#include <stdio.h>
#define MAX 2000
#define IN 1
/* IN means can print aka in printable program */
#define OUT 0
/* OUT means dont print aka outside printable program */

int   ft_load(char *str, int max); /* shisha smoke */
void  ft_clear(char *src, char *dst);

int main(void)
{
  char  commented[MAX];
  char  cleared[MAX];

  //* asdasd */
  ft_load(commented, MAX);
  ft_clear(commented, cleared);
  printf("%s\n", cleared);
  return (0);
}

void  ft_clear(char *src, char *dst)
{
  int i, j;

  i = j = 0;
  while (src[i] != '\0')
  {
    if (src[i] == '\'' || src[i] == '\"') // handle quoted text and copy everything in between
    {
      dst[j] = src[i]; // copy initial quote and go to next character
      j++;
      i++;
      while (src[i] != '\'' && src[i] != '\"' ) // while we have not reached end copy
      {
        dst[j] = src[i];
        j++;
        i++;
      }
      dst[j] = src[i]; /* copy also ending quote */
      j++;
      i++;
    }
    else if (src[i] == '/' && src[i + 1] == '*') // if we encounter a comment
    {
      i = i + 2; // skip to first item after
      while (src[i] != '*' && src[i + 1] != '/') // while dont rech */ skip over
      {
        i++;
      }
      i = i + 2; // skip over */
    }
    else if (src[i] == '/' && src[i + 1] == '/') // handle c++ comments
    {
      i = i + 2;
      while (src[i] != '\n' && src[i + 1] != EOF) // while dont rech */ skip over
      {
        i++;
      }
      dst[j] = src[i]; // put in new line
      j++;
      i++;
    }
    else
    {
      dst[j] = src[i]; // simply copy content
      j++;
      i++;
    }
  }
}

int   ft_load(char *str, int max)
{
  int c, i;

  for (i = 0; i < max - 1 && (c = getchar()) != EOF; i++)
  {
    str[i] = c;
  }
  str[i] = '\0';
  if (i > 0)
  {
    return (1);
  }
  else
  {
    return (0);
  }
}
