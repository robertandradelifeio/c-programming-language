
/*
Exercise 1-13:
  Write a program to print a histogram of the lengths of words in its input.
  It is easy to draw the histogram with the bars horizontal;
  a vertical orientation is more challenging.
*/
#include <stdio.h>

#define IN 1
#define OUT 0
#define BLANK ' '
#define TAB '\t'
#define NEWLINE '\n'

FILE *pFile;
FILE *wFile;

int getTotalCharacters(FILE *pFile)
{
  int c, state, totalWords;
  totalWords = 0;
  state = OUT;

  while ((c = fgetc(pFile)) != EOF)
  {
    if (c == BLANK || c == TAB || c == NEWLINE)
    {
      if (state == IN)
      {
        totalWords++;
      }
      state = OUT;
    }
    else
    {
      state = IN;
    }
  }
  return totalWords;
}

int main()
{
  pFile = fopen("./mocks/tabs-spaces-newlines", "r");
  wFile = fopen("./out/1-13-1.txt", "w");
  if (pFile == NULL)
    perror("Error opening file");
  else
  {

    int totalWords;
    int wordLengths[totalWords];
    int longestWord;
    int currentWordLength;
    int currentWord;
    int c;
    currentWord = currentWordLength = longestWord = 0;
    totalWords = getTotalCharacters(pFile);
    rewind(pFile);
    c = 0;
    while ((c = fgetc(pFile)) != EOF)
    {
      if (c == BLANK || c == TAB || c == NEWLINE)
      {
        if (currentWordLength > 0)
        {
          currentWord++;
        }
        currentWordLength = 0;
      }
      else
      {
        currentWordLength = currentWordLength + 1;
        if (currentWordLength > longestWord)
        {
          longestWord = currentWordLength;
        }
        wordLengths[currentWord] = currentWordLength;
      }
    }

    for (int i = longestWord; i >= 0; i--)
    {
      for (int j = 0; j <= totalWords; j++)
      {
        if (i == 0)
        {
          fprintf(wFile, " %3d ", j + 1);
        }
        else if (wordLengths[j] >= i)
        {
          fprintf(wFile, "   * ", wordLengths[j]);
        }
        else
        {
          fprintf(wFile, "     ");
        }
      }
      fprintf(wFile, "\n");
    }
    fprintf(wFile, "\nTotal words in file:  %3d", totalWords + 1);
  }
  fclose(pFile);
  return 0;
}