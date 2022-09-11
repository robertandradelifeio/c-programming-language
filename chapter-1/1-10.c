
// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int main()
{
    FILE *pFile;
    FILE *wFile;
    int c, spaces, writeMode;
    writeMode = 1;
    spaces = 0;
    pFile = fopen("./mocks/1-8", "r");
    wFile = fopen("./mocks/1-10", "w");
    if (pFile == NULL)
        perror("Error opening file");
    else
    {
        while ((c = fgetc(pFile)) != EOF)
        {
            if (c == ' ')
            {
                fputs("\\s", wFile);
            }
            else if (c == '\t')
            {
                fputs("\\t", wFile);
            }
            else if (c == '\\')
            {
                fputs("\\", wFile);
            }
            else if (c == '\n')
            {
                fputs("\\n\n", wFile);
            }
            else if (c == EOF)
            {
                fputs("oops", wFile);
            }
            else
            {
                putc(c, wFile);
            }
        }
    }
    fclose(pFile);
}