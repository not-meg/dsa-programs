#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100

struct node
{
    int data;
    struct node *next;
};

struct stack
{
    struct node *top;
};

extern void display(struct stack *);

struct node * create_new(int d)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = d;
    new->next = NULL;
    
    return new;
}

void push(struct stack *s, int d)
{
    struct node *new = create_new(d);

    new->next = s->top;
    s->top = new;

    display(s);

    return;
}

void display(struct stack *s)
{
    struct node *temp;

    temp = s->top;

    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct stack s;
    s.top = NULL;

    int d, i, n;

    printf("Enter number of elements to be pushed: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter the data to be pushed: ");
        scanf("%d", &d);
        push(&s, d);
    }
}