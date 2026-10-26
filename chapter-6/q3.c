#include <stdio.h>

int get_gcd(int m, int n)
{
    int remainder;
    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    return m;
}

int main()
{
    int numerator, denominator, remainder;
    printf("Enter a fraction (m/n): ");
    if (scanf("%d/%d", &numerator, &denominator) != 2)
    {
        printf("Invalid input. Please enter a fraction in the form m/n.\n");
        return 1;
    } // but keeps running if one int entered (ex: 5/)

    int gcd = get_gcd(numerator, denominator);

    numerator /= gcd;
    denominator /= gcd;

    printf("Reduced fraction: %d/%d\n", numerator, denominator);

    return 0;
}