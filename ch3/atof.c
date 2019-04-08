#include <stdio.h>

double ft_atof(char *buffer)
{
  double val, power;
  int    i, sign;

  val = 0.0;
  power = 1.0;
  i = 0;
  for ( ; buffer[i] == ' ' || buffer[i] == '\t'; i++);
  sign = (buffer[i] == '-' ? -1 : 1);
  for ( ; buffer[i] == '+' || buffer[i] == '-'; i++);
  while (buffer[i] != '.')
  {
    val = val * 10.0 + (buffer[i] - 48);
    i++;
  }
  i++;
  while (buffer[i] != '\0')
  {
    val = val * 10.0 + (buffer[i] - 48);
    i++;
    power *= 10;
  }
  return (val * sign / power);
}

int main(void)
{
  char    buffer[20] = "98987.25";
  double  d = ft_atof(buffer);
  printf("%f\n", d);
  printf("%f\n", 123.45e-6);
}

/*

typedef struct stack
{
  int database[10];
  int top;
}stack;

void ft_push(stack *s, int val)
{
  s->database[s->top] = val;
  s->top = s->top + 1;
}

int ft_pop(stack *s)
{
  int last = s->database[s->top - 1];
  s->top = s->top - 1;
  return (last);
}

while (i++ < 10) ++ is part of evaluation and is increased after comparison, not after executing loops body

while (i < 10)
    i++

*/
