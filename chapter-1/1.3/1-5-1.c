#include <stdio.h>

/*  Print Fahrenheit to Celsius table
    for F = 300, 280, 260, 240, ..., 0
*/  
void main()
{
    float fahrenheit, celsius;
    printf("Fahrentheit\tCelsius\n");
    printf("-----------------------\n");
    for (fahrenheit = 300; fahrenheit >= 0; fahrenheit = fahrenheit - 20) {
        celsius = (5.0/9.0) * (fahrenheit - 32.0);
        printf("%6.0f\t%14.1f\n", fahrenheit, celsius);
    }
}
