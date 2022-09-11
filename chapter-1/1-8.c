
// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int main()
{
    FILE *pFile;
    int c, spaces, tabs, newLines;
    spaces = 0;
    tabs = 0;
    newLines = 0;
    pFile = fopen("./mocks/1-8", "r");
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
    printf("Number of tabs %d\n\n", tabs);
    printf("Number of spaces %d\n\n", spaces);
    printf("Number of new lines %d\n\n", newLines);

    fclose(pFile);
}