#include <stdio.h>

int ft_getline(char *line, int maxlen, FILE *fp);

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Please, provide files to be displayed\n");
  }
  else
  {
    FILE *fp;
    char buffer[50];
    int page, line, height;

    page = 1;
    line = 1;
    height = 30;

    while (--argc > 0)
    {
      fp = fopen(*++argv, "r");
      while (ft_getline(buffer, 50, fp) != EOF)
      {
        if (line % 30 == 0)
        {
          printf("------%d------\n", page);
          page++;
        }
        printf("%s", buffer);
        line++;
      }
      if (!(--line % 30 == 0))
      {
        while (line % 30 != 0)
        {
          printf("\n");
          line++;
        }
        printf("------%d------\n", page);
        page++;
        line++;
      }
      page = 1;
      line = 1;
    }
  }
}

int ft_getline(char *line, int maxlen, FILE *fp)
{
  int i, c;

  i = 0;
  while ((c = getc(fp)) != EOF && c != '\n' && i < maxlen)
  {
    line[i++] = c;
  }
  if (c == '\n')
  {
    line[i++] = '\n';
  }
  line[i] = '\0';
  return (i == 0 ? EOF : 1);
}

/*
while (--argc > 0)
{
  fp = fopen(*++argv, "r");
  while (ft_getline(buffer, 50, fp) != EOF)
  {
    if (line % 30 == 0)
    {
      printf("------%d------\n", page);
      page++;
    }
    printf("%s", buffer);
    line++;
  }
  if (!(--line % 30 == 0))
  {
    while (line % 30 != 0)
    {
      printf("\n");
      line++;
    }
    printf("------%d------\n", page);
    page++;
    line++;
  }
}
*/
