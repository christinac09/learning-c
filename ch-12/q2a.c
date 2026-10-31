#include <stdio.h>
#include <ctype.h> //for isapha()

/* (a) Write a program that reads a message, then checks whether it's a palindrome:
Enter a message: He lived as a devil, eh?
Palindrome
Enter a message: Madam, I am Adam.
Not a palindrome

Ignore all characters that aren't letters. Use integer variables to keep track of positions in the
array.
*/

int main()
{
    char message[100];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin); // fgets() reads an entire line, including spaces, until it encounters a newline or reaches the array limit (scanf stops at spaces)

    int left = 0, right = 0;
    while (message[right] != '\0')
    { // finding last character by finding \0 first
        right++;
    };
    right--; // move back/left from \0 to get last character

    while (left < right)
    {
        // move past characters that are not letters:
        while (left < right && !isalpha(message[left])) // isalpha() - returns a nonzero value if the char IS a letter, returns 0 if it's NOT a letter. so !isalpha means IS a letter
        {
            left++; // keeps moving forward until encounters letter
        };
        while (left < right && !isalpha(message[right])) // left<right makes sure it stops looking for a character when left becomes > right
        {
            right--;
        }

        if (tolower(message[left]) != tolower(message[right])) // convert all to lowercase
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