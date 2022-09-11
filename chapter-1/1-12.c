#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
  FILE *pFile;
  FILE *wFile;
  int c, state;
  state = OUT;
  pFile = fopen("./mocks/tabs-spaces-newlines", "r");
  wFile = fopen("./out/1-12.txt", "w");
  if (pFile == NULL)
    perror("Error opening file");
  else
  {
    while ((c = fgetc(pFile)) != EOF)
    {
      if (c == ' ' || c == '\t' || c == '\n')
      {
        if (state == IN)
        {
          putc('\n', wFile);
        }
        state = OUT;
      }
      else
      {
        state = IN;
        putc(c, wFile);
      }
    }
  }
  fclose(pFile);
  return 0;
}