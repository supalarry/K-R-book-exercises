#include <stdio.h>

int main(void)
{
  for (int x = 0; x < 10; x++)
  {
    for (int y = 2; y < 12; y++)
    {
      if (y == 5)
      {
        goto damn;
      }
      printf("%d\n", y);
    }
  }

  damn:
    printf("EXIT\n");
  printf("SERBIA\n");
}
