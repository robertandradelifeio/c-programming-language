#include <stdio.h>

/* Print Celsius to Fahrenheit table
    for C = 0, 20, 40, 60, ..., 300
*/  
void main()
{
    float fahrenheit, celsius;
    int lower, upper, step;

    lower = 0;   // lowest temp
    upper = 300; // highest temp
    step = 20;   // step size
    celsius = lower;
    printf("Celsius        Fahrenheit\n");
    printf("-------------------------\n");
    while (celsius <= upper) {
        fahrenheit = (celsius * (9.0 / 5.0)) + 32.0;
        printf("%5.0f\t%14.0f\n", celsius, fahrenheit);
        celsius = celsius + step;
    }
}
