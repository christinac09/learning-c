#include <stdio.h>

// polynomial: 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6

int main() {
    float x;
    printf("Enter a value for x: ");
    
    if (scanf("%f", &x) != 1) { //checks if user input is valid float
        printf("invalid input - please enter an actual number \n");
        return 1;
    };
    //scanf("%f", &x);

    float result = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6; // no exponents in C, so have to multiply it all out
    printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %.2f\n", result);
}