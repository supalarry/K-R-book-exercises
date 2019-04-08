#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100
// max size for buffer where we read numbers and store operator
#define NUMBER '0'
// number is an order on the fact we have stored number in s that we need to push to stack

char ft_getop(char *s);
char ft_getch(void);
void ft_ungetch(char x);
void ft_push(double f);
double ft_pop(void);
void ft_top(void);
void ft_duplicate(void);
void ft_swap(double *one, double *two);
void ft_clear(void);

int main(void)
{
  int type; // we store here answer of reading input and execute upon it
  double op2; // used for / and - operations where order matters
  char s[MAX]; // store read information here
  char next;
  char i;
  char c;
  while ((type = ft_getop(s)) != EOF) // receive command on execution until we hit dead end
  {
    switch (type)
    {
      case NUMBER:
        ft_push(atof(s));
        break;
      case '+':
        ft_push(ft_pop() + ft_pop());
        break;
      case '-':
        next = getchar();
        ft_ungetch(next);
        if (isdigit(next))
        {
          i = 1;
          while (isdigit(s[i++] = c = ft_getch()));
          s[i] = '\0';
          ft_ungetch(c);
          ft_push(atof(s));
        }
        else
        {
          op2 = ft_pop();
          ft_push(ft_pop() - op2);
        }
        break;
      case '*':
        ft_push(ft_pop() * ft_pop());
        break;
      case '/':
        op2 = ft_pop();
        ft_push(ft_pop() / op2);
        break;
      case '%':
        op2 = ft_pop();
        ft_push((int)ft_pop() % (int)op2);
        break;
      case 's':
        ft_push(sin(ft_pop()));
        break;
      case 'e':
        ft_push(exp(ft_pop()));
        break;
      case 'p':
        op2 = ft_pop();
        ft_push(pow(ft_pop(), op2));
        break;
      case '\n':
        //ft_duplicate();
        //ft_clear();
        //printf("%.2f\n", ft_pop());
        printf("%.2f\n", ft_pop());
        //ft_top();
        break;
    }
  }
}

char ft_getop(char *s)
{
  char i, c, o;

  while ((s[0] = c = ft_getch()) == ' ' || c == '\t'); // so the last read character will be num or operator
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != 's' && c != 'e' && c != 'p') // is executed when we encounter operator or newline
  {
    return (c);
  }
  else if (c == 's' || c == 'e' || c == 'p')
  {
    while (isalpha(o = ft_getch()));
    ft_ungetch(o);
    return (c);
  }
  i = 0;
  if (isdigit(c))
  {
    while (isdigit(s[++i] = c = ft_getch()));
  }
  if (c == '.')
  {
    while (isdigit(s[++i] = c = ft_getch()));
  }
  s[i] = '\0'; // if we stored already space in the number we replace it with null char
  if (c != EOF)
  {
    ft_ungetch(c); // for example last read was space thats not part of num, so we put it back in buffer
  }
  return NUMBER; // if we have gotten so far, we didnt return operator or EOF
}

char buffer[MAX];
int bufpos = 0;

char ft_getch(void)
{
  return (bufpos > 0 ? buffer[--bufpos] : getchar());
}

void ft_ungetch(char x)
{
  buffer[bufpos++] = x;
}

double stack[MAX];
int stackpos = 0;

void ft_push(double f)
{
  if (stackpos < MAX)
  {
    stack[stackpos] = f;
  }
  /*if (stackpos > 0)
  {
    ft_swap(&stack[stackpos], &stack[stackpos - 1]);
  }*/
  stackpos++;
}

double ft_pop(void)
{
  if (stackpos > 0)
  {
    return (stack[--stackpos]);
  }
  return (0);
}

// exercise 4-4
void ft_top(void)
{
  printf("%.2f\n", stack[--stackpos]);
}

void ft_duplicate(void)
{
  double temp = stack[stackpos - 1];
  //printf("%f\n", temp);
  stack[stackpos++] = temp;
  //printf("%f\n", stack[stackpos]);
}

void ft_swap(double *one, double *two)
{
  double temp = *one;
  *one = *two;
  *two = temp;
}

void ft_clear(void)
{
  stackpos = 0;
}
