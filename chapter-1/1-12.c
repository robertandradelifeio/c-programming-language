#include <stdio.h>

#define IN 1
#define OUT 0
#define TAB '\t'
#define SPACE ' '
#define NEWLINE '\n'

int main()
{
  char c;
  int state;
  state = OUT;
  while((c = getchar() != EOF))
  {
    if(c != TAB && c != SPACE && c != NEWLINE)
    {
      putchar(c);
      state = IN;
    }
    else if (state == IN)
    {
      putchar('\n');
      state = OUT;
    }
    
  }
  return 0;
}