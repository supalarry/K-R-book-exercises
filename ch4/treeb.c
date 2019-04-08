#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct node
{
  char        *str;
  int         count;
  struct node *left;
  struct node *right;
};

int     ft_getword(char *word, int maxword);
struct  node *ft_create(struct node *head, char *word);
char *ft_strdup(char *word);
void ft_print(struct node *head);

int main(void)
{
  int ans;
  char word[MAXWORD];
  struct node *head;

  head = NULL;
  while (ft_getword(word, MAXWORD) != EOF)
  {
    if (isalpha(word[0]))
    {
      head = ft_create(head, word);
    }
  }
  ft_print(head);
}

struct node *ft_create(struct node *head, char *word)
{
  int i, res;

  i = 0;
  if (head == NULL)
  {
    head = (struct node*)malloc(sizeof(struct node));
    head->str = ft_strdup(word);
    head->count = 1;
    head->left = NULL;
    head->right = NULL;
  }
  else if ((res = strcmp(word, head->str)) == 0)
  {
    head->count++;
  }
  else if (res < 0)
  {
    head->left = ft_create(head->left, word);
  }
  else
  {
    head->right = ft_create(head->right, word);
  }
  return (head);
}

void ft_print(struct node *head)
{
  if (head != NULL)
  {
    ft_print(head->left);
    printf("%s %d\n", head->str, head->count);
    ft_print(head->right);
  }
}

char *ft_strdup(char *word)
{
  char *str;
  int i;
  int len = 0;

  while (word[len] != '\0')
  {
    len++;
  }
  str = malloc(len++);
  for (i = 0; i < len; i++)
  {
    str[i] = word[i];
  }
  str[i] = '\0';
  return (str);
}

int ft_getword(char *word, int maxword)
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
