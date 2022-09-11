#include <stdio.h>

/* Print Fahrenheit to Celsius table
    for F = 0, 20, 40, 60, ..., 300
*/  
void main()
{
    int fahrenheit, celsius;
    int lower, upper, step;

    lower = 0;   // lowest temp
    upper = 300; // highest temp
    step = 20;   // step size
    fahrenheit = lower;
    while (fahrenheit <= upper) {
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("%3d\t%6d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}
