/* User has to input a line of words, and this program
will create vertical histogram based on length of each word */

#include <stdio.h>
#include <stdlib.h>

#define ON 1
#define OFF 0

int   ft_longest(int *arr, int len);

int   main(void)
{
  int c, len;
  char *buffer;

  len = 0; // amount of bytes required for array
  /* Read input and store it as a string */
  /* I could have used linked list so store precisely amount of characters,
  but opted for realloc to practice, so, please, don't judge me :D */
  buffer = (char*)malloc(len);
  while ((c = getchar()) != '\n') // read a line of words
  {
    len++;
    buffer = (char*)realloc(buffer, len);
    buffer[len - 1] = c;
  }
  if (len != 0)
  {
    buffer = (char*)realloc(buffer, len + 1); // add space for null character
    buffer[len] = '\0'; // terminate the buffer with null character
  }
  /* Get count of words */
  int words = 0;
  int state = OFF;
  int index = 0;
  while (buffer[index] != '\0')
  {
    if (buffer[index] == '\t' || buffer[index] == ' ')
    {
      state = OFF;
    }
    else if (state == OFF)
    {
      words++;
      state = ON;
    }
    index++;
  }
  /* Get length of each word and store it in array */
  int *numbers;
  int place = 0;
  int length = 0; // length of a word

  numbers = (int*)malloc(sizeof(int) * words);
  index = 0;
  state = ON;

  while (buffer[index] != '\0')
  {
    if ((buffer[index] >= 'a' && buffer[index] <= 'z') || (buffer[index] >= 'A' && buffer[index] <= 'Z'))
    {
      length++;
      //printf("%c\n", buffer[index]);
      state = ON;
    }
    else if (state == ON)
    {
      numbers[place] = length;
      length = 0;
      place++;
      state = OFF;
    }
    index++;
  }
  numbers[place] = length; // add last digit to numbers array
  /* start printing out vertical bars */
  int huge = ft_longest(numbers, words); // find biggest to know when print empty
  for (int k = 0; k < huge; k++)
  {
    for (int e = 0; e < words; e++)
    {
      if (numbers[e] < huge)
      {
        putchar(' ');
        numbers[e]++;
      }
      else
      {
        putchar('#');
      }
    }
    putchar('\n');
  }
}

int   ft_longest(int *arr, int len)
{
  int biggest = arr[0];

  for (int i = 0; i < len; i++)
  {
    if (arr[i] > biggest)
    {
      biggest = arr[i];
    }
  }
  return (biggest);
}
