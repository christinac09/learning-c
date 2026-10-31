#include <stdio.h>

void reverseArray(int *arr, int n)
{
    int temp;
    int *left = arr;          // first element
    int *right = arr + n - 1; // last element

    while (left < right)
    {
        temp = *left;
        *left = *right;
        *right = temp;

        left++;  // left moves forward/right
        right--; // right goes backward/left
    }
    // should work for odd number arrays too bc the two pointers meet in the middle and the middle element stays the same
}

int main(void)
{
    int data[6] = {1, 2, 3, 4, 5, 6};
    reverseArray(data, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}