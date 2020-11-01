#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("Queue is full");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->rear == q->front)
        printf("Queue is empty");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    int i = q.front + 1;

    do
    {

        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);

    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q, 5);
}