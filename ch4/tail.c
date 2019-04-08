#include <stdio.h>
#define MAXSTORAGE 10000
#define MAXLINES 100
#define IN 1
#define OUT 0

int		ft_atoi(char *str);

static char buffer[MAXSTORAGE];

int main(int argc, char **argv)
{
  char *ptrs[MAXLINES];
  int i, c, n, state, j, lines, linescopy;

  i = j = lines = 0;
  n = 10;
  state = IN;

  if (argc == 2)
  {
    n = ft_atoi(argv[1]);
  }
  while ((c = getchar()) != EOF && i < MAXSTORAGE)
  {
    if (c == '\n')
    {
      lines++;
      linescopy++;
      c = '\0';
    }
    buffer[i] = c;
    i++;
  }
  buffer[i] = '\0';
  i = 0;
  while (lines > 0)
  {
    while (buffer[i] != '\0')
    {
      if (state == IN)
      {
        ptrs[j] = &buffer[i];
        j++;
        state = OUT;
      }
      i++;
    }
    i++;
    lines--;
    state = IN;
  }
  if (linescopy < n)
  {
    for (int x = 0; x < linescopy; x++)
    {
      printf("%s\n", ptrs[x]);
    }
  }
  else
  {
    int forward = linescopy - n;
    for (int x = forward; x < linescopy; x++)
    {
      printf("%s\n", ptrs[x]);
    }
  }
  return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int number;

	i = 0;
	sign = 0;
	number = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
   		{
			i++;
		}
		else if (str[i] == '-')
		{
			if (str[i + 1] -48 >= 0 && str[i + 1] - 48 <= 9)
			{
				sign = 1;
			}
			else
				return (0);
			i++;
		}
		else if (str[i] - 48 >= 0 && str[i] - 48 <= 9)
		{
			number = (number * 10) + (str[i] - 48);
      	if(!(str[i + 1] - 48 >= 0 && str[i + 1] - 48 <= 9))
      	{
        	if (sign == 1)
			{
				return (number);
			}
			else if (sign == 0)
			{
				return (number);
			}
		}
			i++;
		}
		else
			return (0);
	}
	return (0);
}
