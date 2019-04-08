#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100


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

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

int main(void)
{
  int   count;
  char  word[MAXWORD];
  struct key *p;

  count = sizeof(keytab) / sizeof(struct key);
  while (getword(word, MAXWORD) != EOF)
  {
    if (isalpha(word[0]))
    {
      if ((p = binsearch(word, keytab, count)) != NULL)
      {
        p->count++;
      }
    }
  }
  for (p = keytab; p < keytab + count; p++)
  {
    if (p->count != 0)
    {
      printf("Count of %s : %d\n", p->word, p->count);
    }
  }
}

struct key *binsearch(char *word, struct key *tab, int n)
{
  int cond;
  struct key *low, *mid, *high;

  low = &tab[0];
  high = &tab[n--];
  while(low < high)
  {
    mid = low + (high - low) / 2;
    if ((cond = strcmp(word, mid->word)) < 0)
    {
      high = mid;
    }
    else if (cond > 0)
    {
      low = mid + 1;
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
