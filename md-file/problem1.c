#include <stdio.h>

void swap(int *x, int *y)
{
    int temp_x = *x;
    *x = *y;
    *y = temp_x;
}

int main(void)
{
    int x = 3, y = 9;
    printf("Before: x=%d y=%d\n", x, y);
    swap(&x, &y);
    printf("After: x=%d y=%d\n", x, y);
    return 0;
}
