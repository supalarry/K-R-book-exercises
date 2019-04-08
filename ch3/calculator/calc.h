#ifndef CALC_H
#define CALC_H
#include <stdio.h>
#include<stdlib.h>

#define MAXOP 100
#define NUMBER '0'

/* function prototypes */
int getop(char []);
void push(double);
double pop(void);

#define MAXVAL 100  /* maximum depth of val stack */

#include <ctype.h>

int getch(void);
void ungetch(int);

#define BUFSIZE 100
#endif
