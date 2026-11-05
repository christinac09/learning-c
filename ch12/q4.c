/* Simplify Programming Project 2(b) by taking advantage of the fact that an array name can
be used as a pointer. */
#include <stdio.h>
#include <string.h>
#include <ctype.h> //for tolower() and isalpha()

int main()
{
    char message[100];
    printf("Enter a message: ");
    scanf("%[^\n]", message); // read until newline \n

    char *left = message;
    char *right = message + strlen(message) - 1; // last character

    while (left < right)
    {
        while (left < right && !isalpha(*left))
        {
            left++;
        };
        while (left < right && !isalpha(*right))
        {
            right--;
        }

        if (tolower(*left) != tolower(*right))
        {
            printf("Not a palindrome\n");
            return 0;
        };
        left++;
        right--;
    }
    printf("Palindrome\n");
    return 0;
}