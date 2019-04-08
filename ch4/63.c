#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 20

int ft_getword(char *word, int maxlen);

struct appearance
{
  int line;
  struct appearance *next;
};

struct node
{
  char *str;
  struct appearance *link;
  struct node *left;
  struct node *right;
};

struct node *ft_node(struct node *head, char *word);
void ft_print(struct node *head);

static int lines = 1;

int main(void)
{
  int c;
  struct node *head;
  char word[MAXLEN];

  head = NULL;
  while ((c = ft_getword(word, MAXLEN)) != EOF)
  {
    head = ft_node(head, word);
    if (c == '\n')
    {
      lines++;
    }
  }
  ft_print(head);
}

struct appearance *ft_link(struct appearance *head, int lines)
{
  if (head == NULL)
  {
    head = (struct appearance*)malloc(sizeof(struct appearance));
    head->line = lines;
    head->next = NULL;
  }
  else
  {
    head->next = ft_link(head->next, lines);
  }
  return (head);
}

struct node *ft_node(struct node *head, char *word)
{
  int comp;

  if (head == NULL)
  {
    head = (struct node *)malloc(sizeof(struct node));
    head->str = strdup(word);
    head->link = ft_link(NULL, lines);
    head->left = NULL;
    head->right = NULL;
  }
  else if ((comp = strcmp(head->str, word)) > 0)
  {
    head->left = ft_node(head->left, word);
  }
  else if (comp < 0)
  {
    head->right = ft_node(head->right, word);
  }
  else if (comp == 0)
  {
    head->link = ft_link(head->link, lines);
  }
  return (head);
}

int ft_getword(char *word, int maxlen)
{
  int i, c;

  i = 0;
  while ((c = getchar()) == ' ');
  if (c == EOF)
  {
    return (EOF);
  }
  while (isalpha(c))
  {
    word[i++] = c;
    c = getchar();
  }
  word[i] = '\0';
  return (c);
}

void ft_print2(struct appearance *head)
{
  if (head != NULL)
  {
    printf("%d ", head->line);
    ft_print2(head->next);
  }
}

void ft_print(struct node *head)
{
  if (head != NULL)
  {
    ft_print(head->left);
    printf("%s appeared at lines : ", head->str);
    ft_print2(head->link);
    printf("\n");
    ft_print(head->right);
  }
}
