#include <stdio.h>

int main()
{
    int m, n, remainder;
    printf("Enter two integers: ");
    if (scanf("%d %d", &m, &n) != 2)
    {
        printf("Invalid input. Please enter two integers.\n");
        return 1;
    } // doesn't check if the number of integers is 2 tho (keeps running if only one integer is entered)

    while (n != 0)
    {
        remainder = m % n; // euclidean algorithm !!
        m = n;
        n = remainder;
    }
    printf("GCD is: %d\n", m);

    return 0;
}