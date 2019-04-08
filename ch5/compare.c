#include <stdio.h>
#define MAXLEN 100

int ft_getline(char *line, int maxlen, FILE *fp);
int ft_strcmp(char *one, char *two);

int main(int argc, char **argv)
{
  if (argc == 3)
  {
    char line1[MAXLEN];
    char line2[MAXLEN];
    FILE *fp1;
    FILE *fp2;
    int result;

    result = 0;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");
    while (ft_getline(line1, MAXLEN, fp1) != EOF && ft_getline(line2, MAXLEN, fp2) != EOF)
    {
      if (ft_strcmp(line1, line2) != 0)
      {
        printf("Difference spotted:\n");
        printf("%s", line1);
        printf("%s\n", line2);
        result = 1;
      }
    }
    if (result == 0)
    {
      printf("Both texts are equal\n");
    }
    fclose(fp1);
    fclose(fp2);
  }
  else
  {
    printf("Usage : ./compare file1 file2\n");
    return (-1);
  }
}

int ft_strcmp(char *one, char *two)
{
  int i = 0;

  while (one[i] == two[i] && one[i] != '\n' && two[i] != '\n')
  {
    i++;
  }
  return (one[i] - two[i]);
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
