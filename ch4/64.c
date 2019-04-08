#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 20

struct node
{
  char        *word;
  int         freq;
  struct node *left;
  struct node *right;
};

int ft_getword(char *word, int maxlen);
struct node *ft_node(struct node *head, char *word);
void ft_print(struct node *head);
int ft_count(struct node *head);
void ft_store(struct node *head, struct node **arr);
void ft_selection_sort(struct node **arr, int len);

int main(void)
{
  int c;
  struct node *head;
  struct node **arr;
  char word[MAXLEN];

  head = NULL;
  while ((c = ft_getword(word, MAXLEN)) != EOF)
  {
    head = ft_node(head, word);
  }
  int count = ft_count(head);
  arr = (struct node**)malloc(sizeof(struct node) * count);
  ft_store(head, arr);

  ft_selection_sort(arr, count);
  count--;
  for (int x = count; x >= 0; x--)
  {
    printf("%s occured %d times\n", (**(arr + x)).word, (**(arr + x)).freq);
  }
}

void ft_selection_sort(struct node **arr, int len)
{
  int smallest;
  struct node **smallest_ptr;

  for (int x = 0; x < len; x++)
  {
    smallest = (**(arr + x)).freq;
    smallest_ptr = arr + x;

    for (int y = x; y < len; y++)
    {
      if ((**(arr + y)).freq < smallest)
      {
        smallest = (**(arr + y)).freq;
        smallest_ptr = arr + y;
      }
    }
    struct node *temp;
    temp = *(arr + x);
    *(arr + x) = *smallest_ptr;
    *smallest_ptr = temp;
  }
}

struct node **root;

void ft_store(struct node *head, struct node **arr)
{
  root = arr;
  if (head != NULL)
  {
    *root = head;
    root++;
    ft_store(head->left, root);
    ft_store(head->right, root);
  }
}

struct node *ft_node(struct node *head, char *word)
{
  int comp;

  if (head == NULL)
  {
    head = (struct node*)malloc(sizeof(struct node));
    head->word = strdup(word);
    head->freq = 1;
    head->left = NULL;
    head->right = NULL;
  }
  else if ((comp = strcmp(head->word, word)) == 0)
    head->freq++;
  else if (comp < 0)
    head->right = ft_node(head->right, word);
  else
    head->left = ft_node(head->left, word);
  return (head);
}

void ft_print(struct node *head)
{
  if (head != NULL)
  {
    ft_print(head->left);
    printf("%s %d\n", head->word, head->freq);
    ft_print(head->right);
  }
}

int ft_count(struct node *head)
{
  static int i = 0;
  if (head != NULL)
  {
    ft_count(head->left);
    i++;
    ft_count(head->right);
  }
  return (i);
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
