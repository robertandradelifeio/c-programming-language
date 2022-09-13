
/*
Exercise 1-13:
  Write a program to print a histogram of the lengths of words in its input.
  It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/
#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
  FILE *pFile;
  FILE *wFile;
  int c, state, totalWords;
  totalWords = 0;
  state = OUT;
  pFile = fopen("./mocks/tabs-spaces-newlines", "r");
  wFile = fopen("./out/1-13.txt", "w");
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
          totalWords++;
          // putc('\n', wFile);
        }
        state = OUT;
      }
      else
      {
        state = IN;
        // putc(c, wFile);
      }
    }

    fprintf(wFile, "\nTotal words in file:%d\n", totalWords);

      int wordLengths[totalWords];
      int currentWordLength;
      int currentWord;
      currentWord = currentWordLength = 0;
      pFile = fopen("./mocks/tabs-spaces-newlines", "r");
      c = 0;
    while ((c = fgetc(pFile)) != EOF)
    {
      if (c == ' ' || c == '\t' || c == '\n')
      {
        if(currentWordLength > 0) {
          currentWord++;
        }
        currentWordLength = 0;
      }
      else
      {
        currentWordLength = currentWordLength + 1;
        wordLengths[currentWord] = currentWordLength;
      }
    }

    for (int i = 0; i <= totalWords; i++)
    {
      fprintf(wFile, "Length of word %2d: %3d|\t", i + 1, wordLengths[i]);
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