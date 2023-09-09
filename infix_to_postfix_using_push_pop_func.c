#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    char sym;
    struct node *next;
};

void push(struct node **top, int d)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->sym = d;
    new->next = NULL;

    new->next = *top;
    *top = new;
}

char pop(struct node **top)
{
    struct node *temp = *top;
    char d = temp->sym;

    *top = temp->next;

    free(temp);

    return d;
}

int is_operator(char c)
{
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^')) {
        return 1;
    } else {
        return 0;
    }
}

int precedence(char sym)
{
    switch(sym) {
        case '+':
        case '-':
            return 1;
        
        case '*':
        case '/':
            return 2;
        
        case '^':
            return 3;
        
        default:
            return -1;
    }
}

char *infix_to_postfix(char *infix)
{
    int len = strlen(infix), i, j=0;

    char *postfix = (char *)malloc(len+2);

    struct node *top = NULL;

    for(i=0; i<len; i++) {
        if((infix[i] == ' ') || (infix[i] == '\t')) {
            continue;
        }

        if(isalnum(infix[i])) {
            postfix[j] = infix[i];
            j++;
        } else if (is_operator(infix[i])) {
            if(top == NULL) {
                push(&top, infix[i]);
            } else {
                while((top != NULL) && (precedence(top->sym) >= (precedence(infix[i])))) {
                    postfix[j] = pop(&top);
                    j++;
                }
                push(&top, infix[i]);
            }
        } else if ((infix[i] == '(') || (top->sym == '(')) {
            push(&top, infix[i]);
        } else if (infix[i] == ')') {
            while((top != NULL) && (top->sym != '(')) {
                postfix[j] = pop(&top);
                j++;
            }
            pop(&top);
        }
    }
    while(top != NULL) {
        postfix[j] = pop(&top);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    struct node *top = NULL;

    char s[100];

    printf("Enter an expression: ");
    scanf("%s", s);

    char *postfix = infix_to_postfix(s);

    printf("The postfix expression is: %s\n", postfix);
}