#include <stdio.h>

/*
So essentially we can either write struct {..} variable; and now we have created
variable with specific members. If we use tag name struct point {...};
we can rather create new member by using struct point pt;
In a nutshell, if we are not using typedef then we can either create objects
after closing bracker or do it later using tag.

struct point
{
  int x;
  int y;
} one, two, three;

int main(void)
{
  one = {100, 1};
  printf("%d\n", one.x);
}

struct pointer
{
  int x;
  int y;
};

struct rect
{
  struct pointer pt1;
  struct pointer pt2;
};

int main(void)
{
  struct rect screen;
  screen.pt1.x = 50;
}*/


struct point
{
  int x;
  int y;
};

struct rect
{
  struct point pt1;
  struct point pt2;
};

struct point makepoint(int x, int y)
{
  struct point pt = {x, y};
  return (pt);
}

struct point addpoint(struct point one, struct point two)
{
  one.x += two.x;
  one.y += two.y;
  return (one);
}

int ptinrect(struct point one, struct rect screen)
{
  return one.x >= screen.pt1.x && one.x < screen.pt2.x
  && one.y >= screen.pt1.y && one.y < screen.pt2.y;
}


int main(void)
{
  struct point middle;
  struct rect screen;
  screen.pt1 = makepoint(0, 0);
  screen.pt2 = makepoint(5, 10);
  middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);
  printf("%d\n", middle.x);

  struct point ptx = {10,50};
  printf("%d\n", ptx.x);

  struct point *pp; // address of a structure with tag point
  pp = &middle;
  (*pp).x = 10;
  //printf("%d\n", (*pp).x);
  // if pp is a pointer, we can access struct and its element directly
  pp->x = 15;
  //printf("%d\n", pp->x );
}
