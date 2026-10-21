#include <stdio.h>

/* Write a program that asks the user for a 24-hour time, then displays the time in 12-hour form:
Enter a 24-hour time: 21:11
Equivalent 12-hour time: 9:11 PM
Be careful not to display 12:00 as 0:00. */

int main()
{
    int hour, minute;
    char period[3] = "PM"; // for "AM" or "PM"

    printf("Enter a 24-hour time (0:00 to 23:59): ");
    if (scanf("%d:%d", &hour, &minute) != 2)
    {
        printf("Error: Invalid time format entered.\n");
        return 1;
    }
    // integers need pointer b/c it only gives the value, not its location

    int equivalent_hour;

    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) // restrict hour to 0-23 and minute to 0-59
    {
        printf("Error: Invalid time entered.\n");
        return 1;
    }
    else if (hour == 0 && minute == 0)
    {
        equivalent_hour = 12; // 00:00 --> 12:00 AM
        period[0] = 'A';
    }
    else if (hour == 12)
    {
        equivalent_hour = 12; // 12:00 --> 12:00 PM
    }
    else if (hour > 12)
    {
        equivalent_hour = hour - 12;
    }
    else
    {
        equivalent_hour = hour; // for AM times
        period[0] = 'A';
    }

    printf("Equivalent 12-hour time: %d:%02d %s\n", equivalent_hour, minute, period); // 0 tells it to pad w/ 0s for empty spaces, 2 tells it to use 2 digits
}