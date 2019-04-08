#include <stdio.h>

int j = 0;

void ft_store(char start, char finish, char *dst)
{
  for (int i = start; i <= finish; i++)
  {
    dst[j] = i;
    j++;
  }
}

void ft_expand(char *src, char *dst)
{
  int i = 0;
  while (src[i] == '-' && src[i] != '\0')
  {
    if (src[i + 1] != '-')
    {
      dst[j] = '-';
      j++;
    }
    i++;
  }
  while (src[i] != '\0')
  {
    ft_store(src[i], src[i + 2], dst);
    if (src[i + 3] == '-' && (src[i + 4] == '\0' || src[i + 4] == '-'))
    {
      dst[j] = '-';
      j++;
      break;
    }
    else if (src[i + 3] == '-')
    {
      i = i + 2;
      src[i] = src[i] + 1;
    }
    else
    {
      i = i + 3;
    }
  }
  dst[j] = '\0';
}

int main(void)
{
  char src[] = "-a-d0-9-----";
  char dst[40];
  ftt_expand(src, dst);
  printf("%s\n", dst);
}
