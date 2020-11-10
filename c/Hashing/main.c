#include <stdio.h>
#include "Chains.h"
#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

void Insert(int H[], int key)
{
    int index = hash(key);

    if (H[index] != 0)
        index = probe(H, key);
    H[index] = key;
}

void main()
{
    struct Node *HT[10];
    int i;
    for (i = 0; i < 10; i++)
        HT[i] = 0;
}