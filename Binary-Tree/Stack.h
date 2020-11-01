#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int *S;
    int top;
};

void StackCreate(struct Stack *st, int x)
{
    st->size = x;
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");

    st->top++;
    st->S[st->top] = x;
}

int pop(struct Stack *st)
{
    int x = -1;

    if (st->top == -1)
        printf("Stack underflow\n");

    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int isStackEmpty(struct Stack st)
{
    if (st.top == -1)
        return -1;
    return 0;
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        return -1;
    x = st.S[st.top - index + 1];
    return x;
}

int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    return -1;
}

int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];
    return -1;
}
