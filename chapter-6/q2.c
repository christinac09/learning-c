#include <stdio.c>

int main()
{
    int m, n, remainder;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);
    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    printf("GCD is: %d\n", m);

    return 0;
}