#include <stdio.h>
#define abs(x) ((x) < 0 ? -(x) : (x))

void ft_itoa(int num, char *buffer)
{
  static int i = 0;

  if (num / 10)
  {
    ft_itoa(num / 10, buffer);
  }
  else
  {
    if (num < 0)
    {
      buffer[i++] = '-';
    }
  }
  buffer[i++] = abs(num) % 10 + 48;
  buffer[i] = '\0';
}

int main(void)
{
  int   num = -1056;
  char  buffer[50];
  ft_itoa(num, buffer);
  printf("%s\n", buffer);
}
