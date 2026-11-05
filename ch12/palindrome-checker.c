#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* Palindrome checker-  Build a cleaned copy of the string, reverse a second copy, and compare them with strcmp. */

int main()
{
    char message[100];
    char cleaned_message[100];
    char reversed_message[100];

    printf("Enter a message: ");
    scanf("%[^\n]", message);
    char *c = cleaned_message; // pointer to the start of the cleaned message
    for (int i = 0; i < strlen(message); i++)
    {
        if (isalpha(message[i])) // is a letter
        {
            *c = tolower(message[i]);
            c++; // move pointer to next position in cleaned_message
        }
    }
    *c = '\0';

    char *r = reversed_message;
    for (int i = strlen(cleaned_message) - 1; i >= 0; i--)
    {
        *r = cleaned_message[i];
        r++; // move pointer to next position in reversed_message
    }
    *r = '\0';

    if (strcmp(cleaned_message, reversed_message) == 0) // strcmp returns 0 if the strings are equal
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not a palindrome\n");
    };
    return 0;
}