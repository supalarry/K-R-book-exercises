#include <stdio.h>
#define MAX 1000
#define TABSTOP 4
// keep track of current position of element being read
// aka print 4 - (n of the 4 character block eg 0 1 2 3) spaces
// n = current position in new array % 4
int   ft_getline(char *str, int max);
void  ft_tab(char *src, char *dst);

int   main(void)
{
  char buffer[MAX];
  char transfer[MAX];

  int c, counter, len;

  counter = 0;
  while ((len = ft_getline(buffer, MAX)) > 0)
  {
    ft_tab(buffer, transfer);
    printf("%s\n", transfer);
  }
}

void  ft_tab(char *src, char *dst)
{
  int i, pos, spaces;

  i = pos = 0;
  while (src[i] != '\0')
  {
    if (src[i] == '\t')
    {
      spaces = TABSTOP - (pos % TABSTOP);
      //printf("%d\n", spaces);
      for (int x = 0; x < spaces; x++)
      {
        dst[pos] = ' ';
        pos++;
      }
    }
    else
    {
      dst[pos] = src[i];
      pos++;
    }
    //printf("%c at position %d\n", src[i], i);
    i++;
  }
  dst[pos] = '\0';
}

int   ft_getline(char *str, int max)
{
  int c, i;
  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
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

/*
  0 1 2 3  4 5 6 7  8 9 10 11
  0 1 2 3  0 1 2 3  0 1  2  3
  w o r d  \t       w \t */

/* if tab is at location 0, it is 4 - 0 = 4 spaces
after that we count the number of items in block that
aka if in location 0 is letter 'a', counter goes from 0 to 1,
and if then there is a tab, we insert 4 - 1 = 3 spaces.

aka if counter is 0 (being reset after reaching 4) and item is tab,
print 4, else increase counter by one and go up. if tab is reached
print (4 - counter) spaces.

so either we can work with block of 4 or keep track of total number of items.

*/
