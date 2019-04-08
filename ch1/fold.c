#include <stdio.h>
#define MAX 100
#define OK 1
#define NOT 0

int   ft_getline(char *str, int max);
void  ft_coordinates(char *str, int *coordinates, int n);
void  ft_print(char *str, int *coordinates);

int   main(void)
{
  int   len;
  char  buffer[MAX];
  int   coordinates[2];
  int   n = 14;

  while ((len = ft_getline(buffer, MAX)) > 0)
  {
    ft_coordinates(buffer, coordinates, n);
  }
  return (0);
}

void  ft_print(char *str, int *coordinates)
{
  for (int x = coordinates[0]; x < coordinates[1]; x++)
  {
    printf("%c", str[x]);
  }
  printf("\n");
}

void  ft_coordinates(char *str, int *coordinates, int n)
{
  int i, difference, len, state;

  i = 0;
  coordinates[0] = 0;
  state = NOT;
  while (str[i] != '\0') // could try while difference is at least 14 len - i, then flush
  {
    if (i < n) // if we are within our block of interest
    {
      if ((str[i] == ' ' || str[i] == '\t') && str[i - 1] != ' ' && str[i - 1] != '\t')
      { // if element is blank and previous one is not, record that location.
        coordinates[1] = i; // so we can fold here
        state = OK;
      }
    } // prolly have to make a case for if i + 1 == null terminator
    else // problem is that this block is never executed cuz we reached null terminator
    {
      if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
      {
        coordinates[1] = i;
        state = OK;
      }
      if (state == OK)
      {
        ft_print(str, coordinates);
        coordinates[0] = coordinates[1] + 1; // set new position starting after line break
        difference = i - coordinates[1]; // how many letters we are already within new block
        n = n + 14 - difference + 1; // expand n so we can continue with next block
        state = NOT;
      }
      else // in case the word is long and had no spaces
      {
        coordinates[1] = i;
        n = n + 14 + 1;
        ft_print(str, coordinates);
        coordinates[0] = coordinates[1];
      }
    }
    i++;
  }
  coordinates[1] = i;
  ft_print(str, coordinates);
}

int   ft_getline(char *str, int max)
{
  int c, i;

  for (i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; i++)
  {
    str[i] = c;
  }
  if (c == '\n')
  {
    str[i] = c;
    i++;
  }
  str[i] = '\0';
  if (i > 0)
  {
    return (i);
  }
  else
  {
    return (0);
  }
}
