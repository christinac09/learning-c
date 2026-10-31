#include <stdio.h>
#include <ctype.h>
/* (b) Revise the program to use pointers instead of integers to keep track of positions in the
array
Enter a message: He lived as a devil, eh?
Palindrome
Enter a message: Madam, I am Adam.
Not a palindrome*/

int main()
{
    char message[100];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    char *left = message; // first character
    char *right = message;
    while (*right != '\0')
    {
        right++;
    };
    right--; // last character

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