#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  char *str;
  struct node *left;
  struct node *right;
};

struct locker
{
  struct node *node; // address of binary tree storing names
  struct locker *left;
  struct locker *right;
};

void ft_print2(struct node *head)
{
  if (head != NULL)
  {
    ft_print2(head->left);
    printf("%s\n", head->str);
    ft_print2(head->right);
  }
}

void ft_print(struct locker *head)
{
  if (head != NULL)
  {
    ft_print(head->left);
    ft_print2(head->node);
    ft_print(head->right);
  }
}

struct node *ft_node(struct node *location, char *value)
{
  int comp;

  if (location == NULL)
  {
    location = (struct node *)malloc(sizeof(struct node));
    location->str = strdup(value);
    location->left = NULL;
    location->right = NULL;
  }
  else if ((comp = strcmp(location->str, value)) > 0)
  {
    location->left = ft_node(location->left, value);
  }
  else if (comp < 0)
  {
    location->right = ft_node(location->right, value);
  }
  return (location);
}

struct locker *ft_locker(struct locker *location, char *value)
{
  int answ;
  if (location == NULL)
  {
    location = (struct locker *)malloc(sizeof(struct locker));
    location->node = ft_node(NULL, value);
    location->left = NULL;
    location->right = NULL;
  }
  else if ((answ = strncmp(location->node->str, value, 2)) == 0)
  {
    location->node = ft_node(location->node, value);
  }
  else if (answ > 0)
  {
    location->left = ft_locker(location->left, value);
  }
  else
  {
    location->right = ft_locker(location->right, value);
  }
  return (location);
}

int main(void)
{
  /*struct node *head;

  head = NULL;
  head = ft_node(head, "binter");
  head = ft_node(head, "autumn");
  head = ft_node(head, "summer");
  printf("%s\n", head->str);
  printf("%s\n", head->left->str);
  printf("%s\n", head->right->str);*/

  struct locker *head;

  head = NULL;
  head = ft_locker(head, "winter");
  head = ft_locker(head, "wia");
  head = ft_locker(head, "autumn");
  head = ft_locker(head, "aua");
  ft_print(head);
  return (0);
}
