#include <stdio.h>

int main()
{
    fprintf(fopen("./out/1-7.txt", "w"), "this is EOF: %d\n", EOF);
    return EOF;
}
