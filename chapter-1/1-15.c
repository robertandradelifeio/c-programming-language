#include <stdio.h>

/* 
    Exercise 1.15.
    Rewrite the temperature conversion program of Section 1.2
    to use a function for conversion.
*/  

int celsiusToFahrenheit(int degreesFahrenheit)
{
    return 5 * (degreesFahrenheit - 32) / 9;
}

void main()
{
    int fahrenheit, celsius;
    int lower, upper, step;

    lower = 0;   // lowest temp
    upper = 300; // highest temp
    step = 20;   // step size
    fahrenheit = lower;
    while (fahrenheit <= upper) {
        celsius = celsiusToFahrenheit(fahrenheit);
        printf("%3d\t%6d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}
