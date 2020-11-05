#include <stdio.h>

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}
int Delete(int A[], int n)
{
    int i, j, x, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;
    while (j <= n - 1)
    {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
}

void Heapify(int A[], int n)
{
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i = (n / 2) - 1; i >= 0; i--)
    {

        int j = 2 * i + 1; // Left child for current i

        while (j < n - 1)
        {
            // Compare left and right children of current i
            if (A[j] < A[j + 1])
            {
                j = j + 1;
            }

            // Compare parent and largest child
            if (A[i] < A[j])
            {
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    int H[] = {0, 14, 15, 5, 20, 30, 8, 40};
    int i;
    for (i = 2; i <= 7; i++)
        Insert(H, i);

    for (i = 7; i > 1; i--)
    {
        Delete(H, i);
    }
    for (i = 1; i <= 7; i++)
        printf("%d ", H[i]);
    printf("\n");

    return 0;
}