#include <stdio.h>
#define MAX 100

void revescape(char *src, char *dst)
{
  int i, j;

  i = j = 0;
  while (src[i] != '\0')
  {
    if (src[i] == '\\')
    {
      i++;
      switch(src[i])
      {
        case 't':
          dst[j++] = '\t';
          break;
        case 'n':
          dst[j++] = '\n';
          break;
        default:
          dst[j++] = '\\';
          dst[j++] = src[i];
      }
    }
    else
    {
      dst[j++] = src[i];
    }
    i++;
  }
  dst[j] = '\0';
}

int main(void)
{
  char source[MAX] = "I am\tand\n \\:)";
  char destination[MAX];
  revescape(source, destination);
  printf("%s\n", destination);
  return (0);
}
