#include <stdio.h>

/* Modify Programming Project 7 from Chapter 2 to includes the following function:
void pay_amount (int dollars, int *twenties, int *tens, int *fives, int *ones);
The function determines the smallest number of $20, $10, $5, and $1 bills necessary to pay the amount represented by the dollars parameter. The twenties parameter points to a variable in which the function will store the number of $20 bills required. same w the tens, fives, and ones parameters. */

/* chapter 2 project 7: Write a program that asks the user to enter a U.S. dollar amount and then shows how to pay
that amount using the smallest number of $20, $10, $5, and $1 bills:
Enter a dollar amount: 93
$20 bills: 4
$10 bills: 1
$5 bills: 0
$1 bills: 3 */

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / 20; // total and 20 are both integers so c automatically does integer division --> no need to round or use floor()
    dollars %= 20;

    *tens = dollars / 10;
    dollars %= 10;

    *fives = dollars / 5;
    dollars %= 5;

    *ones = dollars;
};

int main(void)
{
    int total, twenties, tens, fives, ones;
    printf("Enter a dollar amount: ");
    if (scanf("%d", &total) != 1)
    {
        printf("Invalid dollar amount. Please enter an integer.\n");
        return 1;
    };

    pay_amount(total, &twenties, &tens, &fives, &ones); // not &total bc don't need its memory address bc not replacing/updating its value

    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf("$5 bills: %d\n", fives);
    printf("$1 bills: %d\n", ones);

    return 0;
}