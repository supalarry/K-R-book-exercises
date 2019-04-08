#include <stdio.h>
#define MAX 100

int     ft_check(char *str);
void    ft_push(double x);
double  ft_pop(void);
double  ft_atof(char *str);

double  stack[MAX];
int     stackp = 0;

int main(int argc, char **argv)
{
  int     sign, num;
  double  op2;

  sign = num = 0;
  while (--argc)
  {
    num = ft_check(*++argv);
    if (num == 1)
    {
      ft_push(ft_atof(*argv));
    }
    else
    {
      printf("%c\n", **argv);
      switch(**argv)
      {
        case '+':
          ft_push(ft_pop() + ft_pop());
          break;
        case '*': /* GOD ONLY KNOWS WHY THIS DOES NOT WORK. ITS WEIRD :DD TRY ./EXPR 2 2 * */
          printf("home\n");
            //ft_push(ft_pop() * ft_pop());
          break;
        case '-':
          op2 = ft_pop();
          ft_push(ft_pop() - op2);
          break;
        case '/':
          op2 = ft_pop();
          ft_push(ft_pop() / op2);
          break;
      }
    }
  }
  printf("%.2f\n", ft_pop());
}

double  ft_atof(char *str)
{
  double num, power;
  int i, sign;

  i = sign = 0;
  num = 0.0;
  power = 1.0;

  while (str[i] == ' ' || str[i] == '\t')
  {
    i++;
  }
  sign = (str[i] == '-' ? -1 : 1);
  while (str[i] == '-' || str[i] == '+')
  {
    i++;
  }
  while (str[i] != '.' && str[i] != '\0')
  {
    num = num * 10 + (str[i] - 48);
    i++;
  }
  if (str[i] == '.')
  {
    i++;
    while (str[i] != '\0')
    {
      power *= 10;
      num = num * 10 + (str[i] - 48);
      i++;
    }
  }
  return (num * sign / power);
}

int ft_check(char *str)
{
  int i, sign, num;

  i = sign = num = 0;
  while (str[i] != '\0')
  {
    if (str[i] == '-')
    {
      sign = 1;
    }
    else if (str[i] >= '0' && str[i] <= '9')
    {
      num = 1;
    }
    i++;
  }
  if ((sign == 1 && num == 1) || (sign == 0 && num == 1))
  {
    return (1);
  }
  else
  {
    return (0);
  }
}

void ft_push(double x)
{
  if (stackp < MAX - 1)
  {
    stack[stackp++] = x;
  }
}

double ft_pop(void)
{
  if (stackp > 0)
  {
    return (stack[--stackp]);
  }
  else
  {
    return (0.0);
  }
}
