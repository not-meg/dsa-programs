#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char ch;
    struct node *next;
};

extern void display(struct node *);

struct node * create_new(char c)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->ch = c;
    new->next = NULL;

    return new;

}

void push(struct node **top, char c)
{
    struct node *new = create_new(c);

    new->next = *top;
    *top = new;

    display(*top);
}

char pop(struct node **top)
{
    struct node *temp;
    char c;

    temp = *top;
    c = temp->ch;

    *top = temp->next;

    free(temp);

    display(*top);

    return c;
}

void display(struct node *top)
{
    struct node *temp;
    temp = top;

    while(temp != NULL) {
        printf("%c\t", temp->ch);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct node *top = NULL;
    char c[100], rev[100];
    int i, len;

    printf("Enter the string to be reversed: ");
    scanf("%s", c);

    len = strlen(c);

    for (i=0; i<len; i++) {
        push(&top, c[i]);
    }

    for(i=0; i<len; i++) {
        rev[i] = pop(&top);
    }
    rev[i] = '\0';

    printf("The reversed string is: %s", rev);
}