#include <stdio.h>

/* Modify Programming Project 9 from Chapter 5 so that each date entered by the user is stored in a date structure (see Exercise 5). Incorporate the compare dates function of Exercise 5 into your program. */
/* Chapter 5 Project 9:
Write a program that prompts the user to enter two dates and then indicates which date comes earlier on the calendar:
Enter first date (mm/dd/yy): 3/6/08
Enter second date (mm/dd/yy): 5/17/07
5/17/07 is earlier than 3/6/08 */

struct date
{
    int month;
    int day;
    int year;
};

int compare_dates(struct date d1, struct date d2)
{
    if (d1.year < d2.year)
        return -1;
    else if (d1.year > d2.year)
        return 1;

    if (d1.month < d2.month)
        return -1;
    else if (d1.month > d2.month)
        return 1;

    if (d1.day < d2.day)
        return -1;
    else if (d1.day > d2.day)
        return 1;

    return 0;
};
// Returns -1 if d1 is earlier than d2, +1 if d1 is later than d2, and 0 if d1 and d2 are the same

int main()
{
    struct date date1, date2;
    printf("Enter first date (mm/dd/yy): ");
    if (scanf("%d/%d/%d", &date1.month, &date1.day, &date1.year) != 3)
    {
        printf("Invalid input. Please enter a valid date in the format mm/dd/yy.\n");
        return 1;
    };
    printf("Enter second date (mm/dd/yy): ");
    if (scanf("%d/%d/%d", &date2.month, &date2.day, &date2.year) != 3)
    {
        printf("Invalid input. Please enter a valid date in the format mm/dd/yy.\n");
        return 1;
    };

    if (compare_dates(date1, date2) == 0)
    {
        printf("%d/%d/%02d and %d/%d/%02d are the same\n", date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);
    }
    else if (compare_dates(date1, date2) == -1)
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d\n", date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);
    }
    else if (compare_dates(date1, date2) == 1)
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d\n", date2.month, date2.day, date2.year, date1.month, date1.day, date1.year);
    }

    return 0;
}