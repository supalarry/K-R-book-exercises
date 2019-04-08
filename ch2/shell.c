#include <stdio.h>

void ft_shellsort(int *nums, int size)
{
  int interval = size / 2;

  while (interval > 0)
  {
    int inner, outer, valToSwap;

    for (outer = interval; outer < size; outer++)
    {
      inner = outer;
      valToSwap = nums[inner]; // bookmark
      while (inner > interval - 1 && nums[inner - interval] > valToSwap)
      {
        nums[inner] = nums[inner - interval];
        inner -= interval;
      }
      nums[inner] = valToSwap;
    }
    interval = interval / 2;
  }
}


void shellsort(int *nums, int n)
{
  int interval = n / 2;
  while (interval > 0)
  {
    int inner, outer, valToSwap;
    for (outer = interval; outer < n; outer++)
    {
      inner = outer;
      valToSwap = nums[inner]; // bookmark
      while (inner > interval - 1 && nums[inner - interval] > valToSwap)
      {
        nums[inner] = nums[inner - interval];
        inner -= interval;
      }
      nums[inner] = valToSwap;
    }
    interval /= 2;
  }
}

void ft_print(int *buf, int len)
{
  int i = 0;
  while (i < len)
  {
    printf("%d ", buf[i]);
    i++;
  }
  printf("\n");
}

int main(void)
{
  int str[] = {4,1,9,2,16,8,20,5,4,155,15,155,2,90,17,66}; // 20
  int len = sizeof(str) / sizeof(int);
  ft_print(str, len);
  ft_shellsort(str, len);
  ft_print(str, len);
  //ft_shellsort(str, 1);
  //printf("%s\n", str);
}
