
/*
Exercise 1-14:
  Write a program to print a histogram of the frequencies of different characters in its input.
*/
#include <stdio.h>

#define IN 1
#define OUT 0
#define BLANK ' '
#define TAB '\t'
#define NEWLINE '\n'

FILE *pFile;
FILE *wFile;

int main()
{
  pFile = fopen("./mocks/tabs-spaces-newlines", "r");
  wFile = fopen("./out/1-14.txt", "w");
  if (pFile == NULL)
    perror("Error opening file");
  else
  {
    int wordLengths[255];
    int currentWordLength;
    int currentWord;
    int c;
    currentWord = currentWordLength = 0;
    c = 0;
    for (int i = 0; i <= 255; i++)
    {
      wordLengths[i] = 0;
    }
    
    while ((c = fgetc(pFile)) != EOF)
    {
      wordLengths[c]++;
    }

    for (int i = 0; i <= 255; i++)
    {
      fprintf(wFile, "%3c:", i);

      for (int j = 0; j < wordLengths[i]; j++)
      {
        fprintf(wFile, "*");
      }
        fprintf(wFile, "\n");
      
    }
  }
  fclose(pFile);
  return 0;
}