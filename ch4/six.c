#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN 1
#define OUT 0
#define MAXLEN 100
//word[i++] = c; take care of arrays
int   ft_getline(char *line, int maxlen);
int   ft_equalsign(char *line);
void  ft_extract1(char *src, char *dst);
int   ft_extract2(char *src, char *dst);
int   ft_isalpha(char letter);
char  *ft_strdup(char *var);

struct node
{
  char *name; // inner binary trees string field
  struct node *left;
  struct node *right;
};

struct tree // structure of the group
{
  struct node *node; // address of another tree's head
  struct tree *left; // address of smaller group
  struct tree *right; // address of bigger group
};

struct node *ft_additem(struct node *head, char *var);
struct tree *ft_addgroup(struct tree *head, char *var);
void ft_print(struct tree *head);
void ft_print2(struct node *head);

int main(int argc, char **argv)
{
  int         count;
  char        var[30];
  char        line[MAXLEN];
  struct tree *head;
  //    struct node *head;

  head = NULL;
  while (ft_getline(line, MAXLEN) != EOF)
  {
    if ((count = ft_equalsign(line)) != -1)
    {
      if (count == 1)
      {
        ft_extract1(line, var);
        head = ft_addgroup(head, var);
        //printf("%s\n", head->node->name);
      }
      else
      {
        while(ft_extract2(line, var));
      }
    }
  }
  ft_print(head);
}

struct node *ft_additem(struct node *head, char *var)
{
  int answ;

  if (head == NULL)
  {
    head = (struct node *)malloc(sizeof(struct node));
    head->name = ft_strdup(var);
    head->left = NULL;
    head->right = NULL;
  }
  else if ((answ = strcmp(head->name, var)) < 0)
  {
    head->right = ft_additem(head->right, var);
  }
  else if (answ > 0)
  {
    head->left = ft_additem(head->left, var);
  }
  return (head);
}

struct tree *ft_addgroup(struct tree *head, char *var)
{
  if (head == NULL)
  {
    head = (struct tree *)malloc(sizeof(struct tree));
    head->node = ft_additem(NULL, var);
    head->left = NULL;
    head->right = NULL;
  }
  else if (strncmp(head->node->name, var, 6) == 0)
  {
    head->node = ft_additem(head->node, var);
  }
  else if (strncmp(head->node->name, var, 2) < 0)
  {
    head->right = ft_addgroup(head->right, var);
  }
  else
  {
    head->left = ft_addgroup(head->left, var);
  }
  return (head);
}

char  *ft_strdup(char *var)
{
  char *str;
  int i = 0;
  while (var[i] != '\0')
  {
    i++;
  }
  str = malloc(i + 1);
  i = 0;
  while (var[i] != '\0')
  {
    str[i] = var[i];
    i++;
  }
  str[i] = '\0';
  return (str);
}

void ft_print2(struct node *head)
{
  if (head != NULL)
  {
    ft_print2(head->left);
    printf("%s\n", head->name);
    ft_print2(head->right);
  }
}

void ft_print(struct tree *head)
{
  if (head != NULL)
  {
    ft_print(head->left);
    ft_print2(head->node);
    ft_print(head->right);
  }
}

void ft_extract1(char *src, char *dst)
{
  int i, j;

  i = j = 0;
  while (src[i] != '=' && src[i - 1] != ' ' && src[i + 1] != ' ')
  {
    i++;
  }
  i--;
  while (src[i] == ' ')
  {
    i--;
  }
  while (ft_isalpha(src[i]))
  {
    i--;
  }
  i++;
  while (ft_isalpha(src[i]))
  {
    dst[j] = src[i];
    j++;
    i++;
  }
  dst[j] = '\0';
}

int ft_extract2(char *src, char *dst)
{
  static int i = 1;
  int j, pos;

  j = pos = 0;
  while (src[i] != '\0')
  {
    while (src[i] != '=' && src[i - 1] != ' ' && src[i + 1] != ' ')
    {
      if (src[i] == '\0')
      {
        return (0);
      }
      i++;
    }
    pos = i;
    i--;
    while (src[i] == ' ')
    {
      i--;
    }
    while (ft_isalpha(src[i]))
    {
      i--;
    }
    i++;
    while (ft_isalpha(src[i]))
    {
      dst[j] = src[i];
      j++;
      i++;
    }
    dst[j] = '\0';
    i = pos + 1;
    return (1);
  }
  return (0);
}

int ft_equalsign(char *line)
{
  int i, equalsign, count, prohibited;

  i = equalsign = count = prohibited = 0;
  while (line[i] != '\0')
  {
    if (line[i] == '=' && line[i - 1] == ' ' && line[i + 1] == ' ')
    {
      equalsign = 1;
      count++; // save position of last equal sign encountered
    }
    i++;
  }
  return (equalsign == 1 ? count : -1);
}

int ft_getline(char *line, int maxlen)
{
  int i, c;

  i = 0;
  while ((c = getchar()) != '\n' && c != EOF && i < maxlen)
  {
    line[i++] = c;
  }
  if (c == '\n')
  {
    line[i++] = '\n';
  }
  else if (c == EOF)
  {
    return (EOF);
  }
  line[i] = '\0';
  return (i);
}

int ft_isalpha(char letter)
{
  if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
  {
    return (1);
  }
  return (0);
}
