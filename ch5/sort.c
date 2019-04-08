#include <stdio.h>

int   ft_store(char **ptrs, char *buffer);
void  ft_print(char **ptrs, int lines);
void  ft_selection_sort(char **ptrs, int lines);
int   ft_strcmp(char *one, char *two);
void  ft_swap(char **one, char **two);

int main(void)
{
  char *ptrs[10];
  char buffer[1000];

  int lines = ft_store(ptrs, buffer) - 1;
  ft_selection_sort(ptrs, lines);
  ft_print(ptrs, lines);
  return (0);
}

int ft_store(char **ptrs, char *buffer)
{
  int i, j, c;

  i = j = c = 0;
  while (c != EOF)
  {
    *(ptrs + j) = buffer + i;
    j++;
    while ((c = getchar()) != '\n' && c != EOF)
    {
      buffer[i++] = c;
    }
    if (c == '\n')
    {
      buffer[i++] = '\0';
    }
  }
  return (j);
}

// sort array's numbers usint selection sort
// to get arr_len, in main write arr_len = sizeof(array) / sizeof(int);
void   ft_selection_sort(char **ptrs, int lines)
{
  char *smallest; // address of first char of string
  char **smallest_ptr; // address of address

  for (int x = 0; x < lines; x++) // loop through all elements
  {
    smallest = *(ptrs + x); // first element of unsorted part
    smallest_ptr = ptrs + x; // unsorted part's first element's address
    for (int y = x; y < lines; y++) // for each step in array, loop through
    { // rest of the numbers
      if (ft_strcmp(*(ptrs + y), smallest) < 0) // if any number in unsorted part is smaller
      { // than already smallest number
        smallest = *(ptrs + y); // then smallest is that number
        smallest_ptr = ptrs + y; // and address of smallest is updated
      }
    }
    ft_swap(ptrs + x, smallest_ptr); // here we swap smallest found value
  } // with first element of unsorted array. we then increase x stepping one
} // step further, so we leave sorted elements behind our back.

void ft_swap(char **one, char **two)
{
  char *temp = *one;
  *one = *two;
  *two = temp;
}

int ft_strcmp(char *one, char *two)
{
  int i = 0;
  while (one[i] == two[i] && one[i] != '\0' && two[i] != '\0')
  {
    i++;
  }
  return (one[i] - two[i]);
}

void ft_print(char **ptrs, int lines)
{
  int i = 0;
  while (lines > 0)
  {
    printf("%s\n", ptrs[i]);
    i++;
    lines--;
  }
}
