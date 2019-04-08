#include <stdio.h>

int main(int argc, char **argv)
{
  FILE  *fp;
  int   counter, c;

  counter = 1;
  while (counter < argc)
  {
    if ((fp = fopen(argv[counter], "r")))
    {
      while ((c = getc(fp)) != EOF)
      {
        putc(c, stdout);
      }
    }
    counter++;
  }
  fclose(fp);
  return (0);
}
