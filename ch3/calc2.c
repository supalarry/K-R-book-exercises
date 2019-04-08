#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int ft_getline(char *buffer, int max);
int ft_isdigit(char x);
void ft_push(double f);
double ft_pop(void);

double  data[MAX];
int     datap = 0;

int main(void)
{
  int     answer;
  int     index;
  int     sign;
  double  op2;
  char    buffer[MAX];

  index = 0;
  sign = 0;
  while ((answer = ft_getline(buffer, MAX)) == 1)
  {
    while (buffer[index] != '\0')
    {
      if (ft_isdigit(buffer[index]))
      {
        int   i = 0;
        char  buf[MAX];
        while (buffer[index] != ' ')
        {
          if (sign == 1)
          {
            buf[i++] = '-';
            sign = 0;
          }
          buf[i] = buffer[index];
          i++;
          index++;
        }
        buf[i] = '\0';
        ft_push(atof(buf));
      }
      switch (buffer[index])
      {
        case '+':
          ft_push(ft_pop() + ft_pop());
          break;
        case '-':
          if (ft_isdigit(buffer[index + 1]))
          {
            sign = 1;
            break;
          }
          op2 = ft_pop();
          ft_push(ft_pop() - op2);
          break;
        case '*':
          ft_push(ft_pop() * ft_pop());
          break;
        case '/':
          op2 = ft_pop();
          ft_push(ft_pop() / op2);
          break;
        case '\n':
          printf("%.2f\n", ft_pop());
          datap = 0;
          break;
      }
      index++;
    }
    index = 0;
  }
}

int ft_isdigit(char x)
{
  return (x >= '0' && x <= '9' ? 1 : 0);
}

int ft_getline(char *buffer, int max)
{
  int i, c;
  for (i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; i++)
  {
    buffer[i] = c;
  }
  if (c == '\n')
  {
    buffer[i++] = c;
  }
  buffer[i] = '\0';
  return (i > 0 ? 1 : 0);
}

void ft_push(double f)
{
  if (datap < MAX)
  {
    data[datap++] = f;
  }
}

double ft_pop(void)
{
  if (datap > 0)
  {
    return (data[--datap]);
  }
  return (0.0);
}
