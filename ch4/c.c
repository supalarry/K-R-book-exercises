#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

int getword(char *word, int maxword);
struct key *compare(char *word, struct key *tab, int n);

struct key
{
  char  *word;
  int   count;
};

struct key keytab[] =
{
  {"auto", 0},
  {"break", 0},
  {"case", 0},
  {"char", 0},
  {"const", 0},
  {"continue", 0},
  {"default", 0},
  {"unsigned", 0},
  {"void", 0},
  {"volatile", 0},
  {"while", 0}
};

int main(void)
{
  int i, n;
  char word[MAXWORD];
  struct key *ptr;

  n = sizeof(keytab) / sizeof(struct key);
  while ((i = getword(word, MAXWORD)) != EOF)
  {
    if (isalpha(word[0]))
    {
      if ((ptr = compare(word, keytab, n)) != NULL)
      {
        ptr->count++;
      }
    }
  }
  for (ptr = keytab; ptr < keytab + n; ptr++)
  {
    printf("%s %d\n", ptr->word, ptr->count);
  }
}

struct key *compare(char *word, struct key *tab, int n)
{
  int res;
  struct key *low, *mid, *high;

  low = tab;
  high = tab + n;

  while (low < high)
  {
    mid = low + (high - low) / 2;
    if ((res = strcmp(word, mid->word)) > 0)
    {
      low = mid + 1;
    }
    else if (res < 0)
    {
      high = mid - 1;
    }
    else
    {
      return (mid);
    }
  }
  return (NULL);
}

int getword(char *word, int maxword)
{
  int i, c;

  i = 0;
  while (isspace(c = getchar()));
  if (c != EOF)
  {
    while (isalpha(c))
    {
      word[i++] = c;
      c = getchar();
    }
    word[i] = '\0';
    return word[0];
  }
  else
  {
    return EOF;
  }
}
