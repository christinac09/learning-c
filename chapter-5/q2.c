#include <stdio.h>

/* Write a program that asks the user for a 24-hour time, then displays the time in 12-hour form:
Enter a 24-hour time: 21:11
Equivalent 12-hour time: 9:11 PM
Be careful not to display 12:00 as 0:00. */

int main()
{
    int hour;
    char minute[2];
    printf("Enter a 24-hour time: ");
    scanf("%d:%s", &hour, minute); // why does one need to use & for hour but not for minute?

    int equivalent_hour;
    if (hour > 12)
    {
        equivalent_hour = hour - 12;
    }
    else
    {
        equivalent_hour = hour; // for 12:00
    }

    printf("Equivalent 12-hour time: %d:%s PM\n", equivalent_hour, minute);
}