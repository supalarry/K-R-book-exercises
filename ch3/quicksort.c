#include <stdio.h>

void ft_print(int *v, int end);

void ft_swap(int *one, int *two)
{
  int temp = *one;
  *one = *two;
  *two = temp;
}

int ft_ip(int *v, int start, int end)
{
  int pivot = v[end]; // 4
  int ip = start;

  for (int i = start; i < end; i++)
  {
    if (v[i] <= pivot)
    {
      ft_swap(&v[ip], &v[i]);
      ip++;
    }
  }
  ft_swap(&v[ip], &v[end]);
  return (ip);
}

void ft_quick(int *v, int start, int end)
{
  if (start < end)
  {
    int ip = ft_ip(v, start, end);
    ft_print(v, 7);
    ft_quick(v, start, ip - 1);
    ft_quick(v, ip + 1, end);
  }
}

int main(void)
{
  int v[] = {7, 2, 1, 6, 8, 5, 3, 4};
  int end = sizeof(v) / sizeof(int) - 1;
  ft_print(v, end);
  ft_quick(v, 0, end);
  ft_print(v, end);
}

void ft_print(int *v, int end)
{
  int i = 0;
  while (i <= end)
  {
    printf("%d", v[i]);
    i++;
  }
  printf("\n");
}
