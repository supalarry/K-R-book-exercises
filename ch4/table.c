#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

struct node
{
  char *name; // defined name aka IN
  char *replacement_text; // replace IN with 1
  struct node *next;
};

struct node *database[MAX];

struct node *ft_lookup(char *name);
void ft_install(char *name, char *replace);
void ft_print(struct node **head);
unsigned ft_hash(char *s);
void ft_undef(char *name);
struct node *ft_previous(char *name);

int main(void)
{
  for (int i = 0; i < MAX; i++)
  {
    database[i] = NULL;
  }
  ft_install("IN", "1");
  ft_install("OUT", "0");
  ft_undef("IN");
  ft_print(database);
  return (0);
}

struct node *ft_previous(char *name)
{
  unsigned int index = ft_hash(name);
  struct node *head = database[index];

  if (head->next == NULL)
  {
    return (NULL);
  }
  while (head != NULL)
  {
    if (strcmp(head->next->name, name) == 0)
    {
      return (head);
    }
    head = head->next;
  }
}

void ft_undef(char *name)
{
  struct node *head = ft_previous(name);
  if (head != NULL)
  {
    struct node *head_new = head->next->next;
    head->next = head_new;
  }
  else
  {
    unsigned int index = ft_hash(name);
    database[index] = NULL;
  }
}

void ft_print(struct node **head)
{
  static int count = 0;
  if (count < MAX && head[count] != NULL)
  {
    printf("%s ", head[count]->name);
    printf("%s\n", head[count]->replacement_text);
    count++;
    ft_print(head);
  }
  else if (count < MAX)
  {
    count++;
    ft_print(head);
  }
}

struct node *ft_node(struct node *head, char *name, char *replace)
{
  if (head == NULL)
  {
    head = (struct node *)malloc(sizeof(struct node));
    head->name = strdup(name);
    head->replacement_text = strdup(replace);
    head->next = NULL;
  }
  else
  {
    head->next = ft_node(head->next, name, replace);
  }
  return (head);
}

void ft_install(char *name, char *replace)
{
  struct node *head = ft_lookup(name);

  if (head != NULL)
  {
    head->name = strdup(name);
  }
  else
  {
    unsigned int index = ft_hash(name);
    database[index] = ft_node(database[index], name, replace);
  }
}

struct node *ft_lookup(char *name)
{
  unsigned int index = ft_hash(name);
  struct node *head = database[index];

  while (head != NULL)
  {
    if (strcmp(head->name, name) == 0)
    {
      return (head);
    }
    head = head->next;
  }
  return (NULL);
}

unsigned ft_hash(char *s)
{
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++)
  {
    hashval = *s + 31 * hashval;
  }
  return (hashval % MAX);
}
