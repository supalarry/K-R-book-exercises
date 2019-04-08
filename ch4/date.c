#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int day_of_year(int year, int month, int day) // 02 / 14th -> 31 + 14 = 45
{
  int leap;
  char *ptr;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  ptr = daytab[leap] + 1;
  while (--month)
  {
    day += *ptr;
    ptr++;
  }
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int leap;
  char *ptr;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  ptr = daytab[leap] + 1;
  while (yearday > *ptr)
  {
    yearday = yearday - *ptr;
    ptr++;
  }
  *pday = yearday;
  *pmonth = ptr - daytab[leap];
}

int main(void)
{
  int pmonth;
  int pday;

  month_day(2018, 41 ,&pmonth, &pday);
  printf("Month: %d\n", pmonth);
  printf("Day: %d\n", pday);
  return (0);
}
