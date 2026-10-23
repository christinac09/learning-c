#include <stdio.h>

int main()
{
    int numerator, denominator, remainder;
    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);
    while (n != 0)
    {
        remainder = numerator % denominator;
        numerator = denominator;
        denominator = remainder;
    }

    int gcd = numerator;

    int reduced_numerator = numerator / gcd;
    int reduced_denominator = denominator / gcd;

    printf("Reduced fraction: %d/%d\n", reduced_numerator, reduced_denominator);

    return 0;
}