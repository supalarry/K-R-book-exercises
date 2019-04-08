#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{ // count characters, words and lines
  // nc = characters nw = words nl = lines
  int c, nc, nw, nl, state, count;

  nc = nw = nl = count = 0;
  state = OUT;

  while ((c = getchar()) != EOF)
  {
    nc++;
    if (c == '\n')
      nl++;
    if (c == '\t' || c == ' ' || c == '\n')
    {
      state = OUT;
    }
    else if (state == OUT)
    {
      state = IN;
      count++;
    }
  }
  printf("%d\n", count);

  /* Print words in new line
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF)
  {
    if (c != '\t' && c != ' ')
    {
      putchar(c);
      state = IN;
    }
    else if (state == IN)
    {
      putchar('\n');
      state = OUT;
    }*/
  }
}
