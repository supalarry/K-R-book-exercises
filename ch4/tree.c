#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct node
{
  char  *word;
  int   count;
  struct node *left;
  struct node *right;
};

struct node *addtree(struct node *head, char *word);
void printtree(struct node *head);
struct node *talloc(void);
char *ft_strdup(char *word);
int getword(char *, int);

int main(void)
{
  char word[MAXWORD];
  struct node *head;

  head = NULL;
  while(getword(word, MAXWORD) != EOF)
  {
    if (isalpha(word[0]))
    {
      head = addtree(head, word);
    }
  }
  printtree(head);
}

struct node *addtree(struct node *head, char *word)
{
  int answ;

  if (head == NULL)
  {
    head = talloc();
    head->word = strdup(word);
    head->count = 1;
    head->left = NULL;
    head->right = NULL;
  }
  else if ((answ = strcmp(word, head->word)) == 0)
  {
    head->count++;
  }
  else if (answ < 0)
  {
    head->left = addtree(head->left, word);
  }
  else
  {
    head-> right = addtree(head->right, word);
  }
  return (head);
}

char *ft_strdup(char *word)
{
  int i, j;
  char *str;

  i = 0;
  while(word[i] != '\0')
  {
    i++;
  }
  str = malloc(i++);
  for (int j = 0; j < i; j++)
  {
    str[j] = word[j];
  }
  str[j] = '\0';
  return (str);
}

struct node *talloc(void)
{
  return (struct node *)malloc(sizeof(struct node));
}

void printtree(struct node *head)
{
  if (head != NULL)
  {
    printtree(head->left);
    printf("%s %d\n", head->word, head->count);
    printtree(head->right);
  }
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
