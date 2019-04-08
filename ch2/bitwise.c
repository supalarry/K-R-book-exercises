#include <stdio.h>

/*unsigned bitmap(unsigned int x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
  return (x >> (p + 1 - n)) & ~(~0 << n);
}*/

void ft_print_bits(int x)
{
  for (int i = 31; i >= 0; i--)
  {
    int value = x >> i;
    if (value & 1)
    {
      printf("1");
    }
    else
    {
      printf("0");
    }
  }
  printf("\n");
}

/*int ft_bitcount(int x)
{
  int count = 0;
  for (int x = 31; x >= 0; x--)
  {
    int digit = digit >> x;
    if (digit & 1)
    {
      count++;
    }
  }
}*/

/*unsigned invert(unsigned int x, int p, int n)
{
  //int bitmask = ~((~0) << n);
  //return ((y & bitmask) << p) | (~(bitmask << p) & x);
  ft_print_bits(182);
  int bitmask = ~(~0 << n); // 0000 0000 1111
  ft_print_bits(bitmask);
  int part = ~((bitmask << p) & x); // 0000 1111 0000 & x and then flip the result to get 1111 0010 1111
  ft_print_bits(part);
  int left = 32 - n - p; // count of bits to left
  int right = n; // count of bits to right
  part = part >> right; // shift right
  part = part << right; // then shift back so 1's are 0's now
  part = part << left; // shift left
  part = part >> left; // then shift back so 1's are 0' now
  ft_print_bits(part);
  // now we should have 0000 0010 0000
  return (~(bitmask << p) & x) | part;
}*/

/*int ft_bitcount(unsigned int x)
{
  int pos = 0;
  for (int i = 0; i < 32; i++)
  {
    int num = x >> i;
    if (num & 1)
    {
      pos++;
    }
  }
  return (pos);
}

int   bitcount(unsigned int x)
{
  int b;

  for (b = 0; x != 0; x = x & (x - 1))
  {
    b++;
  }
  return (b);
}*/

/*unsigned ft_rotate(unsigned int x, int n)
{
  ft_print_bits(x);
  int mask1 = ~(~0 << n);
  int side1 = x & mask1;

  int mask2 = ~mask1;
  int side2 = x & mask2;

  side2 = side2 >> n;
  int slide = ft_bit_count(x) - n;
  side1 = side1 << slide;

  return (side1 | side2);
}*/



int main(int argc, char **argv)
{
  if (argc == 2)
  {
    ft_lower(argv[1]);
  }
  return (0);
}
