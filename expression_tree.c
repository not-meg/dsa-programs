#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 50

struct node
{
    char sym;
    struct node *left;
    struct node *right;
};

struct stack
{
    int top;
    struct node *stack[MAX];
};

void push(struct stack *s, struct node *n)
{
    if((s->top) == MAX-1) {
        return;
    } else {
        (s->top)++;
        s->stack[s->top] = n;
        return;
    }
}

struct node * pop(struct stack *s)
{
    if(s->top == -1) {
        return NULL;
    } else {
        struct node *n = s->stack[s->top];
        (s->top)--;

        return n;
    }
}

struct node * create_node(char c)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->sym = c;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void create_tree(struct node **root, struct stack *s)
{
    int i, len;
    char c;

    char postfix[MAX];
    struct node *new;

    printf("Enter a postfix expression: ");
    scanf("%s", &postfix);

    len = strlen(postfix);

    for(i=0; i<len; i++) {
        if ((postfix[i] == ' ') || (postfix[i] == '\t')) {
            continue;
        }

        new = create_node(postfix[i]);
        if(isalnum(new->sym)) {
            push(s, new);
        } else {
            *root = new;
            (*root)->right = pop(s);
            (*root)->left = pop(s);

            push(s, *root);
        }
    }
}

float postfix_eval(struct node *root)
{
    switch(root->sym) {
        case '+':
            return postfix_eval(root->right) + postfix_eval(root->left);
            break;
        
        case '-':
            return postfix_eval(root->right) - postfix_eval(root->left);
            break;

        case '*':
            return postfix_eval(root->right) * postfix_eval(root->left);
            break;

        case '/':
            return postfix_eval(root->right) / postfix_eval(root->left);
            break;

        case '^':
            return pow(postfix_eval(root->right), postfix_eval(root->left));
            break;

        default:
            return root->sym - '0';
            break;
    }
}

int main()
{
    struct stack s;
    s.top = -1;

    struct node *root = NULL;
    float res;

    create_tree(&root, &s);

    res = postfix_eval(root);

    printf("Result: %.3f\n", res);


}