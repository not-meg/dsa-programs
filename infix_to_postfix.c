#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int precedence(char op)
{
    switch(op)
    {
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

int is_operator(char ch)
{
    if((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '^')) {
        return 1;
    } else {
        return 0;
    }
}

char * infix_to_postfix(char *infix)
{
    int len = strlen(infix);

    char *postfix = (char *)malloc(len + 2);

    char stack[100];

    int top = -1, j = 0, i;

    for(i=0; i<(len+2); i++) {
        postfix[i] = '\0';
    }

    for (i=0; i<len; i++) {
        if ((infix[i] == ' ') || (infix[i] == '\t')) {
            continue;
        }

        if(isalnum(infix[i])) {
            postfix[j] = infix[i];
            j++;
        } else if(is_operator(infix[i])) {
            if (top == -1) {
                stack[++top] = infix[i];
            } else {
                while((precedence(stack[top]) >= precedence(infix[i])) && (top != -1)) {
                    postfix[j] = stack[top];
                    j++;
                    top--;
                }
                stack[++top] = infix[i];
            }
        }

        if((infix[i] == '(') || ((stack[top] == '(') && (is_operator(infix[i])) )) {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while ((top > -1) && (stack[top] != '(')) {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top--;
        } 
    }

    while (top != -1) {
        if (stack[top] == '(' || stack[top] == ')') {
            return "Invalid expression.";
        }
        postfix[j] = stack[top];
        j++;
        top--;
    }

    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char infix[100], *postfix;
    
    printf("Enter an expression: ");
    scanf("%s", infix);

    postfix = infix_to_postfix(infix);

    printf("The postfix expression is: %s", postfix);

    free(postfix);
}