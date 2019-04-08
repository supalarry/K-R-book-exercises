/* Basically, user can input one number at a time in input and it is then
converted to int and stored int buffer. Conversion is needed, because if one
write '1012' in input, it is just a string which needs to be converted for
storing in buffer, as it holds integers */

#include <stdio.h>
#include <ctype.h>
#define SIZE 50

int ft_getint(int *num)
{
  int c, sign;

  while ((c = getchar()) == ' ' || c == '\t');
  if (c != EOF && c != '-' && c != '+' && !isdigit(c))
  {
    return (0);
  }
  sign = (c == '-' ? -1 : 1);
  if (c == '-' || c == '+')
  {
    c = getchar();
  }
  for (*num = 0; isdigit(c); c = getchar())
  {
    *num = *num * 10 + (c - 48);
  }
  *num *= sign;
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
  {
    printf("%c\n", c);
  }
  return (*num); // we return num because any non 0 value will be seen as true
}

int main(void)
{
  int i;
  int buffer[SIZE];

  for (i = 0; i < SIZE && ft_getint(&buffer[i]); i++);

  //int size = sizeof(buffer) / sizeof(int);
  
  /*for (int x = 0; x < size; x++)
  {
    printf("%d\n", buffer[x]);
  }*/
}
