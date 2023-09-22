#include <stdio.h>

#define STACKSIZE 100

int empty(int *top)
{
    if (*top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int overflow(int *top)
{
    if (*top == (STACKSIZE-1)) {
        return 1;
    } else {
        return 0;
    }
}

void display(int *top, int *items)
{
    int i;

    if (empty(top)) {
        printf("Stack is empty.\n");
        fflush(stdout);
        return;
    }

    for (i=(*top); i>=0; i--) {
        printf("items[%d] = %d\n", i, items[i]);
        fflush(stdout);
    }

    printf("\n");
    fflush(stdout);

    return;
}

void push(int *top, int *items, int d)
{
    if (overflow(top)) {
        printf("Stack is full. Cannot push into stack.\n");
        fflush(stdout);
        return;
    } else {
        ++(*top);

        printf("top = %d\n", *top);
        
        items[*top] = d;
        
        display(top, items);

        return;
    }
}

int pop(int *top, int *items)
{
    int d;

    if (empty(top)) {
        printf("Stack is empty. Cannot pop from stack.\n");
        return -1;
    } else {
        d = items[*top];
        (*top)--;

        display(top, items);
        
        return d;
    }
}

int peek(int *top, int *items)
{
    int d;
    
    if (empty(top)) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        d = items[*top];
        return d;
    }
}

int main()
{
    int top = -1, data, pop_val, n, i;
    int items[STACKSIZE];

    printf("Enter the number of items to be pushed: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        printf("Enter the data to be pushed: ");
        scanf("%d", &data);
        push(&top, items, data);
    }

    printf("Enter the number of items to be popped: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        pop_val = pop(&top, items);
    }
}
