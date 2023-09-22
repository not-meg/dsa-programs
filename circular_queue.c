#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * create_new(int d)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = d;
    new->next = NULL;

    return new;
}

void enqueue(struct node **front, struct node **rear, int d)
{
    struct node *new = create_new(d);

    if(*front == NULL) {
        *front = new;
        *rear = new;
        new->next = new;

        return;
    }

    struct node *temp;
    (*rear)->next = new;
    *rear = new;
    new->next = *front;

    return;
}

int dequeue(struct node **front, struct node **rear)
{
    if(*front == NULL) {
        return -1;
    }

    int d;

    if(*front == *rear) {
        d = (*front)->data;
        *front = NULL;
        *rear = NULL;

        return d;
    }

    struct node *temp = *front;

    d = temp->data;
    *front = temp->next;

    free(temp);

    (*rear)->next = *front;

    return d;
}

void display(struct node *front, struct node *rear)
{
    if(front == NULL) {
        return;
    }

    struct node *temp = front;

    while(temp != rear) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("%d", temp->data);

    printf("\n");
}

int main()
{
    struct node *front = NULL, *rear = NULL;

    int n, d, i;

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter data to be enqueued: ");
        scanf("%d", &d);

        enqueue(&front, &rear, d);
    }

    display(front, rear);

    printf("Enter number of elements to dequeue: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        d = dequeue(&front, &rear);

        if(d != -1) {
            printf("Dequeued element: %d\n", d);
        }
    }

    printf("\nQueue:\t");
    display(front, rear);
}