#include <stdio.h>

/* Print Fahrenheit to Celsius table
    for F = 0, 20, 40, 60, ..., 300
*/  
void main()
{
    float fahrenheit, celsius;
    int lower, upper, step;

    lower = 0;   // lowest temp
    upper = 300; // highest temp
    step = 20;   // step size
    fahrenheit = lower;
    printf("Fahrentheit\tCelsius\n");
    printf("-----------------------\n");
    while (fahrenheit <= upper) {
        celsius = (5.0/9.0) * (fahrenheit - 32.0);
        printf("%6.0f\t%14.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}
