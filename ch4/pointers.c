#include <stdio.h>


void ft_strcat(char *body, char *tail, int n)
{
  int counter = 0;
  while (*body != '\0')
  {
    body++;
  }
  while (*tail != '\0' && counter < n)
  {
    *body = *tail;
    tail++;
    body++;
    counter++;
  }
  *body = '\0';
}

int ft_strend(char *body, char *tail)
{
  int i = 0;
  int j = 0;

  while (*(body + i) != '\0')
  {
    i++;
  }
  while (*(tail + j) != '\0')
  {
    j++;
  }
  for ( ; j > 0 && *(body + i) == *(tail + j); j--, i--);

  return (*(body + i) - *(tail + j));
}

int main(void)
{
  char body[100] = "My name is: ";
  char tail[] = "El Jeffe";

  ft_strcat(body, tail, 4);
  printf("%s\n", body);
  return (0);
}
