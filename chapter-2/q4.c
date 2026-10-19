#include <stdio.h>

int main()
{
    float subtotal;
    printf("Enter a dollar and cent amount: ");  // adding \n makes user input in next line, no \n makes user input on same line

    //make sure the user enters the correct data type:
     if (scanf("%f", &subtotal) != 1)   // scanf("%f", &subtotal) reads and stores user's input
    {
        printf("Invalid input! Please enter a number.\n");
        return 1; //returning nonzero value means error & stops program
    }

    float tax_rate = 0.05;

    float total = subtotal * (tax_rate + 1);
    printf("Total with tax: %.2f\n", total); // prints total with 2 decimal places

    return 0;
}