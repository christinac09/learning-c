/* 1. (a) Write a program that reads a message, then prints the reversal of the message:
Enter a message: Don't get mad, get even.
Reversal is: .neve teg, dam teg t'noD
Hint: Read the message one character at a time (using getchar) and store the characters in an array. Stop reading when the array is full or the character read is'\n'.
(b) Revise the program to use a pointer instead of an integer to keep track of the current position in the array. */

#include <stdio.h>
#include <string.h>

// 1a.
/* int main(void)
{
    char message[100];
    int i = 0;

    printf("Enter a message: ");

    while (i < 100 && (message[i] = getchar()) != '\n') // getchar() reads characters one at a time until \n
    {
        i++;
    }
    message[i] = '\0'; // end the string

    printf("Reversal is: ");
    for (i = strlen(message) - 1; i >= 0; i--)
    {
        printf("%c", message[i]); // print characters one at a time backwards
    }
    printf("\n");

    return 0;
} */

// 1b.
int main(void)
{
    char message[100];
    char *p = message; // pointer to the start of the array

    printf("Enter a message: ");
    while (p < message + 100 && (*p = getchar()) != '\n') // read characters until \n or array is full
    {
        p++; // p moves down array
    }
    *p = '\0';

    printf("Reversal is: ");
    for (p--; p >= message; p--) // move pointer back to the last character
    {
        printf("%c", *p); // print characters one at a time backwards
    }
    printf("\n");
    return 0;
}