#include <stdio.h>

/* Write a program that translates an alphabetic phone number into numeric form:
Enter phone number: CALLATT
2255288
(In case you don't have a telephone nearby, here are the letters on the keys: 2=ABC, 3=DEF,
4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY.) If the original phone number contains
nonalphabetic characters (digits or punctuation, for example), leave them unchanged:
Enter phone number: 1-800-COL-LECT
1-800-265-5328
You may assume that any letters entered by the user are upper case. */

int main()
{
    char phone_number[20];
    printf("Enter phone number: ");
    scanf("%s", phone_number);

    for (int i = 0; phone_number[i] != '\0'; i++)
    {
        switch (phone_number[i])

        case 'A':
        case 'B':
        case 'C':
            phone_number[i] = '2';
        break;
    case 'D':
    case 'E':
    case 'F':
        phone_number[i] = '3';
        break;
    case 'G':
    case 'H':
    case 'I':
        phone_number[i] = '4';
        break;
    case 'J':
    case 'K':
    case 'L':
        phone_number[i] = '5';
        break;
    case 'M':
    case 'N':
    case 'O':
        phone_number[i] = '6';
        break;
    case 'P':
    case 'R':
    case 'S':
        phone_number[i] = '7';
        break;
    case 'T':
    case 'U':
    case 'V':
        phone_number[i] = '8';
        break;
    case 'W':
    case 'X':
    case 'Y':
        phone_number[i] = '9';
        break;
    }

    printf("%s\n", phone_number);

    return 0;
}