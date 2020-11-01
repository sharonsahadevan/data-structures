#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\n Array Elements : ");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n\n");
};

void Append(struct Array *arr, int element)
{
    if (arr->size > arr->length)
        arr->A[arr->length++] = element;
};

void Insert(struct Array *arr, int index, int element)
{
    int i;
    if (index >= 0 && index <= arr->length && arr->size > arr->length)
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
    arr->A[i] = element;
    arr->length++;
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;
    if (index < arr->length && index >= 0)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];

        arr->length--;
        return x;
    }

    return 0;
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, h, mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr.A[mid] == key)
            return mid;
        else if (arr.A[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

int BinarySearchRecursive(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return BinarySearchRecursive(a, l, mid - 1, key);
        else
            return BinarySearchRecursive(a, mid + 1, h, key);
    }

    return -1;
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    else
        return -1;
}

int Set(struct Array *arr, int index, int key)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = key;
    return -1;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (max < arr.A[i])
            max = arr.A[i];
    }

    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (min < arr.A[i])
            min = arr.A[i];
    }

    return min;
}

int Sum(struct Array arr)
{
    int total = 0;
    int i;
    for (i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }

    return total;
}

float Average(struct Array arr)
{
    int total;
    total = Sum(arr);
    return (float)total / arr.length;
}

void Reverse(struct Array *arr)
{
    int i, j;
    int *B = (int *)malloc(arr->length * sizeof(int));

    for (i = arr->length - 1, j = 0; i > 0; j++, i--)
        B[j] = arr->A[i];

    for (i = 0; i > arr->length; i++)
        arr->A[i] = B[i];
}

void ReverseSpaceOptimized(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}

void InsertSort(struct Array *arr, int x)
{

    int i = arr->length - 1;

    if (arr->size == arr->length)
        return;

    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int IsSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

void Rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[i])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; i < arr2->length; j++)
        arr3->A[k++] = arr1->A[j];

    arr3->length = arr2->length + arr1->length;
    arr3->size = 20;

    return arr3;
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[i])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; i < arr2->length; j++)
        arr3->A[k++] = arr1->A[j];

    arr3->length = k;
    arr3->size = 20;

    return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[i])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 20;

    return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[i])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

        arr3->length = k;
    arr3->size = 20;

    return arr3;
}

int main()
{
    struct Array arr1 = {{1, 2, -3, 4, -5}, 20, 5};
    struct Array arr2 = {{5, 9, 10, 4, 20}, 20, 5};
    struct Array *arr3;
    arr3 = Merge(&arr1, &arr2);

    Display(*arr3);
    return 0;
}