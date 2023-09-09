#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

extern void display(struct node *);

struct node *create_new(int d)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = d;
    new->next = NULL;

    return new;

}

void push(struct node **top, int d)
{
    struct node *new = create_new(d);

    new->next = *top;
    *top = new;

    display(*top);
}

int pop(struct node **top)
{
    struct node *temp;
    int d;

    if (top == NULL) {
        printf("Stack is empty.");
        return -1;
    }

    temp = *top;
    *top = temp->next;
    d = temp->data;

    free(temp);

    display(*top);

    return d;   
}

void display(struct node *top)
{
    struct node *temp;

    if (top == NULL) {
        printf("Stack is empty");
        return;
    }

    temp = top;

    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("\n");
    return;
}

int main()
{
    struct node *top = NULL;
    int d, n, i, pop_val;

    printf("Enter number of items to push onto the stack: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        printf("Enter item to be pushed: ");
        scanf("%d", &d);

        push(&top, d);
    }

    printf("Enter number of items to be popped: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        pop_val = pop(&top);
        printf("Popped value = %d\n\n", pop_val);
    }


}