#include <stdio.h>

/* European countries use a 13 - digit code, known as a European Article Number(EAN). Each EAN ends with a check digit. The technique for calculating the check digit is also similar:

    Add the second, fourth, sixth, eighth, tenth, and twelfth digits.
    Add the first, third, fifth, seventh, ninth, and eleventh digits.
    Multiply the first sum by 3 and add it to the second sum.
    Subtract 1 from the total.
    Compute the remainder when the adjusted total is divided by 10.
    Subtract the remainder from 9.

example:
    Enter the first 12 digits of an EAN: 869148426000
    Check digit: 8 */

int main()
{
    char first_12[12];
    printf("Enter the first 12 digits of an EAN: ");
    scanf("%s", first_12);

    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < 12; i++)
    {
        int digit = first_12[i];
        if (i % 2 == 0)
        {
            sum1 += digit;
        }
        else
        {
            sum2 += digit;
        }
    }

    int total = sum1 * 3 + sum2;
    int adjusted_total = total - 1;
    int remainder = adjusted_total % 10;
    int check_digit = 9 - remainder;

    printf("Check digit: %d\n", check_digit);

    return 0;
}