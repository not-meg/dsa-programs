#include <stdio.h>

#define STACKSIZE 100

struct stack
{
    int top;
    int items[STACKSIZE];
};

extern int empty(struct stack *);
extern int overflow(struct stack *);

int empty(struct stack *ps)
{
    if (ps->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int overflow(struct stack *ps)
{
    if (ps->top == (STACKSIZE-1)) {
        return 1;
    } else {
        return 0;
    }
}

void display(struct stack *ps)
{
    int i;

    printf("\nStack:\n");

    if (empty(ps)) {
        printf("Stack is empty.\n");
        fflush(stdout);
        return;
    }

    if (ps == NULL) {
        printf("display : ps is NULL\n");
        return;
    }

    for (i=ps->top; i>=0; i--) {
        printf("%d\t", ps->items[i]);
        fflush(stdout);
    }

    printf("\n");
    fflush(stdout);

    return;
}

void push(struct stack *ps, int d)
{
    if (overflow(ps)) {
        printf("Stack is full. Cannot push into stack.\n");
        fflush(stdout);
        return;
    } else {
        if (ps ==  NULL) {
            return;
        }
        ++(ps->top);
        
        ps->items[ps->top] = d;

        return;
    }
}

int pop(struct stack *ps)
{
    int d;

    if (empty(ps)) {
        printf("Stack is empty. Cannot pop from stack.\n");
        return -1;
    } else {
        d = ps->items[ps->top];
        (ps->top)--;

        return d;
    }
}

int peek(struct stack *ps)
{
    int d;
    
    if (empty(ps)) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        d = ps->items[ps->top];
        return d;
    }
}

int main()
{
    struct stack ps;
    int data, pop_val, n, i;

    ps.top = -1;

    printf("Enter the number of items to be pushed: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        printf("Enter the data to be pushed: ");
        scanf("%d", &data);
        push(&ps, data);
    }

    display(&ps);

    printf("Enter the number of items to be popped: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        pop(&ps);
    }

    display(&ps);

    data = peek(&ps);
    if(data != -1) {
        printf("Peeking: %d\n", data);
    }

    data = empty(&ps);
    if(data == 1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    data = overflow(&ps);
    if(data == 1) {
        printf("Stack is full.\n");
    } else {
        printf("Stack is not full.\n");
    }
}
