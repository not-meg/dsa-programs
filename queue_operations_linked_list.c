#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * create_node(int d)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));

    new->data = d;
    new->next = NULL;
}

void insert(struct node **front, struct node **rear, int d)
{
    struct node *new = create_node(d);

    if(*front == NULL) {
        *front = new;
        *rear = new;
        return;
    }

    struct node *temp = *front;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new;
    *rear = new;
    
    return;
}

int delete(struct node **front, struct node **rear)
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

    return d;
}

int main()
{
    struct node *front = NULL, *rear = NULL;

    int n, d, i;

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter data to enqueue: ");
        scanf("%d", &d);

        insert(&front, &rear, d);
    }

    printf("Enter number of elements to dequeue: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        d = delete(&front, &rear);

        if(d != -1) {
            printf("Dequeued element: %d\n", d);
        }
    }
}