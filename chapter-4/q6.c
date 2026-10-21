#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* European countries use a 13 - digit code, known as a European Article Number(EAN). Each EAN ends with a check digit. The technique for calculating the check digit is also similar:
    Add the second, fourth, sixth, eighth, tenth, and twelfth digits.
    Add the first, third, fifth, seventh, ninth, and eleventh digits.
    Multiply the first sum by 3 and add it to the second sum.
    Subtract 1 from the total.
    Compute the remainder when the adjusted total is divided by 10.
    Subtract the remainder from 9.

Example:
    Enter the first 12 digits of an EAN: 869148426000
    Check digit: 8 */

int main(void) // void indicates that the function doesn't take any parameters
{
    char first_12[13]; // 13 is needed for the 12 digits & the null terminator '\0'

    printf("Enter the first 12 digits of an EAN: ");

    if (scanf("%12s", first_12) != 1 || strlen(first_12) != 12) // checks that the input is exactly 12 digits and scanf successfully read a string
    {
        printf("Invalid input. Please enter exactly 12 digits.\n");
        return 1;
    }

    for (int i = 0; i < 12; i++) // checks that each character is a digit
    {
        if (!isdigit(first_12[i]))
        {
            printf("Invalid input. Please enter digits only.\n");
            return 1;
        }
    }

    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < 12; i++)
    {
        int digit = first_12[i] - '0'; // converts char to int b/c it uses ASCII values

        if (i % 2 == 0) // even indexes (0,2,...) --> odd positions (1st, 3rd, ..., 11th)
        {
            sum2 += digit;
        }
        else // odd indexes (1,3,...) --> even positions (2nd, 4th, ..., 12th)
        {
            sum1 += digit;
        }
    }

    int total = sum1 * 3 + sum2;
    int check_digit = (10 - total % 10) % 10;

    printf("Check digit: %d\n", check_digit);

    return 0;
}