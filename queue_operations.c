#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 100

struct queue
{
    int a[MAXQUEUE];
    int front;
    int rear;
};

void enqueue(struct queue *q, int d)
{
    if(q->rear == -1) {
        q->front++;
        q->rear++;
        q->a[q->rear] = d;

        return;
    }

    if(q->rear == MAXQUEUE-1) {
        return;
    }

    q->rear++;
    q->a[q->rear] = d;

    return;
}

int dequeue(struct queue *q)
{
    if(q->rear == -1) {
        return -1;
    }

    int d;

    if(q->rear == q->front) {
        d = q->a[q->rear];

        q->front = -1;
        q->rear = -1;

        return d;
    }

    d = q->a[q->front];

    int i;

    for(i=1; i<=q->rear; i++) {
    q->a[i-1] = q->a[i];
    }

    q->rear--;

    return d;
}

void display(struct queue *q)
{
    if(q->front == -1) {
        return;
    }

    int temp = q->front;

    while(temp <= q->rear) {
        printf("%d\t", q->a[temp]);
        temp++;
    }

    printf("\n");
}

int main()
{
    struct queue q;
    q.front = -1;
    q.rear = -1;

    int n, d, i;

    printf("Enter the number of elements to be enqueued: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter the element to be enqueued: ");
        scanf("%d", &d);
        enqueue(&q, d);
    }

    display(&q);

    printf("Enter the number of elements to be dequeued: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        d = dequeue(&q);

        if(d != -1) {
            printf("Dequeued element: %d\n", d);
        }
    }

    printf("Queue:\n");

    display(&q);
}