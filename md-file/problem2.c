#include <stdio.h>

void minMax(int *arr, int n, int *min, int *max)
{
    for (int i = 0; i < n; i++)
    {
        /* if (arr[i] < *min)
        {
            *min = arr[i];
        }
        if (arr[i] > *max)
        {
            *max = arr[i];
        } */

        // using pointer arithmetic:
        if (*(arr + i) < *min)
        {
            *min = arr[i];
        }
        if (*(arr + i) > *max)
        {
            *max = arr[i];
        }
    }
}

int main(void)
{
    int data[5] = {4, -2, 9, 0, 7};
    int lo, hi;
    minMax(data, 5, &lo, &hi);
    printf("min = %d, max = %d\n", lo, hi);
    return 0;
}