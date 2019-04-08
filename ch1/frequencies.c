/* User has to input a line of words, and this program
will create vertical histogram based on length of each word */

#include <stdio.h>
#include <stdlib.h>

int   ft_count(int *arr);
int   ft_biggest(int *arr);

int   main(void)
{
  int characters[95] = {0};
  int c;

  while ((c = getchar()) != EOF)
  {
    if (c >= 32 && c <= 126)
    {
      characters[c - 32] = characters[c - 32] + 1;
    }
  }
  int huge = ft_biggest(characters);
  int count = ft_count(characters);

  int *useful;
  useful = (int*)malloc(sizeof(int) * count);
  int index = 0;
  for (int k = 0; k < 95; k++)
  {
    if (characters[k] != 0)
    {
      useful[index] = characters[k];
      index++;
    }
  }

  for (int i = 0; i < huge; i++)
  {
    for (int j = 0; j < count; j++)
    {
      if (useful[j] < huge)
      {
        putchar(' ');
        useful[j]++;
      }
      else
      {
        putchar('#');
      }
    }
    putchar('\n');
  }
}

int   ft_count(int *arr)
{
  int counter = 0;
  for (int i = 0; i < 95; i++)
  {
    if (arr[i] != 0)
    {
      counter++;
    }
  }
  return (counter);
}

int   ft_biggest(int *arr)
{
  int biggest = arr[0];
  for (int i = 0; i < 95; i++)
  {
    if (arr[i] > biggest)
    {
      biggest = arr[i];
    }
  }
  return (biggest);
}
