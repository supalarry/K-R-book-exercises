#include <stdio.h>
#define MAX 50

void  escape(char *src, char *dst)
{
  int i, j;

  i = j = 0;
  while (src[i] != '\0')
  {
    switch(src[i])
    {
      case '\t':
        dst[j++] = '\\';
        dst[j++] = 't';
        break;
      case '\n':
        dst[j++] = '\\';
        dst[j++] = 'n';
        break;
      default:
        dst[j++] = src[i];
        break;
    }
    i++;
  }
  dst[j] = '\0';
}

int   main(void)
{
  char source[MAX] = "I am \t just a hidden \n and as";
  char dest[MAX];
  escape(source, dest);
  printf("%s\n", dest);
  return (0);
}

/*int i, c, whitespaces, digits[10], others;

for (i = 0; i < 10; i++)
{
  digits[i] = 0;
}
others = whitespaces = 0;
while ((c = getchar()) != EOF)
{
  switch(c)
  {
    case '1': case '2': case '3': case '4': case '5': case '6': case '7':
    case '8': case '9':
      digits[c - 48]++;
      break;
    case '\t': case ' ': case '\n':
      whitespaces++;
      break;
    default:
      others++;
      break;
  }
}
for (i = 0; i < 10; i++)
{
  printf("%d occured %d times\n", i , digits[i]);
}
printf("Whitespaces %d Others %d\n", whitespaces, others);*/
