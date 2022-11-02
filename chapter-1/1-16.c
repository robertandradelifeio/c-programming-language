#include <stdio.h>

#define MAXLINE 1000 /* max length of line*/

int get_line(char line[], int maxline); /* declare get line function */
void copy(char from[], char to[]); /* declare copy line function */

void main()
{
    int len; // longest line
    char line[MAXLINE]; // array storing all characters in line

    int maxlen; // longest line seen so far
    char maxline[MAXLINE]; // array containing longest line

    maxlen = 0; // start at 0
    while ((len = get_line(line, MAXLINE)) > 0) //as long as lines are longer than 0
    {
        if (maxlen < len) // if current line is longer than previous max
        {
            maxlen = len; // current line is set to max
            copy(line, maxline); //copy current line to maxline array
        }

        printf("line_length: %d\n", len); // print length of current line
    }

    if (maxlen > 0)
    {
        printf("%s", maxline); // print length of longest line
    }
}

int get_line(char line[], int maxline) // takes in one line, and int for longest possible line
{
    int c, i;

    for (i = 0; i <= maxline && (c = getchar()) != EOF && c != '\n'; ++i) // while there are still characters to read and line isn't longer than maxline (1000)
    {
        line[i] = c; // set current character to index in array
    }
    if (c == '\n') // if there's a newline character
    {
        line[i] = c; // set current index to newline char
        ++i; //increment i one more time so we can store \0 as last char in array
    }

    line[i] = '\0'; // store \0 as last char in array

    while (c != EOF && c != '\n') //go through each char in array 
    {
        ++i; // increment i for each char in array
        c = getchar();
    }
    return i; // return length of array
}

void copy(char from[], char to[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0') //copy until you get '\0'
    {
        ++i;
    }
}