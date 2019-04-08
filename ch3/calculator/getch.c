#include "calc.h"

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;
/* getch: the function which actually gets chars! */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back in input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
