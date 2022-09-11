
// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int main()
{
    FILE *pFile;
    FILE *oFile;
    int c, spaces, tabs, newLines;
    spaces = 0;
    tabs = 0;
    newLines = 0;
    pFile = fopen("./mocks/tabs-spaces-newlines", "r");
    oFile = fopen("./out/1-8.txt", "w");
    if (pFile == NULL)
        perror("Error opening file");
    else
    {
        do
        {
            c = fgetc(pFile);
            if (c == '\t')
            {
                tabs++;
            }
            if (c == '\n')
            {
                newLines++;
            }
            if (c == ' ')
            {
                spaces++;
            }
            //    printf("%d\n", c);
        } while (c != EOF);
    }
    fprintf(oFile, "Number of tabs: %d\n", tabs);
    fprintf(oFile, "Number of spaces: %d\n", spaces);
    fprintf(oFile, "Number of new-lines: %d", newLines);

    fclose(pFile);
}