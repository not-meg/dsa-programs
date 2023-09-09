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
        printf("ps->items[%d] = %d\n", i, ps->items[i]);
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
            printf("ps is NULL\n");
            return;
        }
        ++(ps->top);

        printf("top = %d\n", ps->top);
        
        ps->items[ps->top] = d;
        
        display(ps);

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

        display(ps);
        
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

    printf("Enter the number of items to be popped: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        pop(&ps);
    }

    peek(&ps);
    empty(&ps);
    overflow(&ps);
}