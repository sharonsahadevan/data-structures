#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
        }
    }
}
void main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    Bubble(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}