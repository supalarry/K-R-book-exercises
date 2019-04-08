// Store all input lines in one big array and create array of pointers.
// This program sorts input lines in alphabetical order and prints them.
#include <stdio.h>
#include <string.h>
#define MAX 500
#define LINES 10
#define IN 1
#define OUT 0

int ft_store(char *database);
void ft_map(char *database, char **pointers, int lines);
void ft_sort(char **pointers, int lines);
void ft_swap(char **base, char **compared);
void ft_print(char **pointers, int lines);
int ft_compare(char *one, char *two);

int main(void)
{
  char database[MAX]; // store all input lines into one big array. Terminated with \0
  char *pointers[LINES]; // store address of first character of line stored in database
  int lines;

  lines = ft_store(database); // store user input
  ft_map(database, pointers, lines); // store addresses of first character of each line
  ft_sort(pointers, lines);
  ft_print(pointers, lines);
}

int ft_store(char database[]) // text input in array
{
  int i, c, lines;

  i = lines = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      *(database + i) = '\0';
      lines++;
    }
    else
    {
      *(database + i) = c;
    }
    i++;
  }
  return (lines);
}

void ft_map(char *database, char **pointers, int lines) // create pointer array
{
  int i, j, state;

  i = j = 0;
  state = IN;

  while (lines > 0)
  {
    while (*(database + i) != '\0')
    {
      if (state == IN)
      {
        *(pointers + j) = database + i;
        j++;
        state = OUT;
      }
      i++;
    }
    state = IN;
    i++;
    lines--;
  }
}

void ft_sort(char **pointers, int lines)
{
  int counter;
  int iterations;

  counter = -1;
  iterations = 0;
  while (counter != 0)
  {
    counter = 0;
    for (int i = 0; i < lines - iterations - 1; i++)
    {
      char *base = *(pointers + i);
      char *compared = *(pointers + i + 1);
      if (ft_compare(base, compared))
      {
        counter++;
        ft_swap(pointers + i, pointers + i + 1);
      }
    }
    iterations++;
  }
}

int ft_compare(char *one, char *two)
{
  int i = 0;

  while (one[i] == two[i] && one[i] != '\0' && two[i] != '\0')
  {
    i++;
  }
  if (one[i] > two[i])
  {
    return (1);
  }
  return (0);
}

void ft_swap(char **base, char **compared)
{
  char *temp = *base;
  *base = *compared;
  *compared = temp;
}

void ft_print(char **pointers, int lines)
{
  int i = 0;

  while (lines > 0)
  {
    printf("%s\n", *(pointers + i));
    i++;
    lines--;
  }
}
