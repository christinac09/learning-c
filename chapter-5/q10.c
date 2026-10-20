#include <stdio.h>
#include <math.h> // for floor function

/* Using the switch statement, write a program that converts a numerical grade into a letter grade:
Enter numerical grade: 84
Letter grade: B
Use the following grading scale: A = 90-100, B = 80-89, С = 70–79, D = 60-69, F=0-59.
Print an error message if the grade is larger than 100 or less than 0. Hint: Break the grade into two digits, then use a switch statement to test the ten's digit. */

int main()
{
    int grade;
    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    int tens_digit = floor(grade / 10);

    switch (tens_digit)
    {
    case 9:
    case 10:
        printf("Letter grade: A\n");
        break;
    case 8:
        printf("Letter grade: B\n");
        break;
    case 7:
        printf("Letter grade: C\n");
        break;
    case 6:
        printf("Letter grade: D\n");
        break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:
        printf("Letter grade: F\n");
        break;
    default:
        printf("Error: Grade cannot be greater than 100 or less than 0.\n"); // not working for negatives
        break;
    }
    return 0;
}