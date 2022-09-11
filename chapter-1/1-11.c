#include <stdio.h>
#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */
void main()
{
    int c, nl, nw, nc, state;
    FILE *IN_FILE;
    FILE *OUT_FILE;
    state = OUT;
    nl = nw = nc = 0;
    IN_FILE = fopen("./mocks/tabs-spaces-newlines", "r");
    OUT_FILE = fopen("./out/1-11.txt", "w");
    while ((c = fgetc(IN_FILE)) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    fprintf(OUT_FILE, "Newlines: %d\nNew words: %d\nNew characters: %d\n", nl, nw, nc);
}