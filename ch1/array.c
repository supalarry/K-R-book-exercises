#include <stdio.h>

/* Count numbers, whitespaces and other characters */
int   main(void)
{
  int array[10]; //store occurance for numbers from 0 to 9
  int whitespaces = 0; // store tabs, spaces and new lines
  int others = 0; // store all other characters
  int c; // store read character

  for (int i = 0; i < 10; i++)
  {
    array[i] = 0;
  }
  while ((c = getchar()) != EOF)
  {
    if (c >= '0' && c <= '9')
    {
      array[c - 48] = array[c - 48] + 1;
    }
    else if (c == '\t' || c == '\n' || c == ' ')
    {
      whitespaces++;
    }
    else
    {
      others++;
    }
  }
  printf("Digits : ");
  for (int j = 0; j < 9; j++)
  {
    printf("%i occured %i times\n", j + 1, array[j]);
  }
  printf("Whitespaces : %i\n", whitespaces);
  printf("Others : %i\n", others);
}
