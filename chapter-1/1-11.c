
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
    pFile = fopen("./mocks/tabs-spaces-newlines", "r");
    wFile = fopen("./out/1-11.txt", "w");
    if (pFile == NULL)
        perror("Error opening file");
    else
    {
        do
        {
            c = fgetc(pFile);
            if (c == ' ')
            {
                if (writeMode == 1)
                {
                    putc(c, wFile);
                }
                writeMode = 0;
            }
            if (c != ' ')
            {
                writeMode = 1;
                putc(c, wFile);
            }
        } while (c != EOF);
    }
    printf("Number of spaces %d\n\n", spaces);

    fclose(pFile);
}