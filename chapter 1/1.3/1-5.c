#include <stdio.h>

/*  Print Celsius to Fahrenheit table
    for F = 300, 280, 260, 240, ..., 0
*/  
void main()
{
    float fahrenheit, celsius;
    printf("Celsius        Fahrenheit\n");
    printf("-------------------------\n");
    for (celsius = 300; celsius >= 0; celsius = celsius - 20) {
        fahrenheit = (celsius * (9.0 / 5.0)) + 32.0;
        printf("%5.0f\t%14.0f\n", celsius, fahrenheit);
    }
}
