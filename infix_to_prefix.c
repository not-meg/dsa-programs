#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void reverse_string(char * str)
{
    int i, len = strlen(str);
    char temp;

    for(i=0; i<(len-1)/2; i++)
    {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }

    for (i=0; i<len; i++) {
        if (str[i] == '(') {
            str[i] = ')';
        } else if (str[i] == ')') {
            str[i] = '(';
        }
    }

    printf("Reversed: %s\n", str);
}

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

char * infix_to_prefix(char *infix)
{
    int len = strlen(infix);

    reverse_string(infix);

    char *prefix = (char *)malloc(len + 2);

    char stack[100];

    int top = -1, j = 0, i;

    for(i=0; i<(len+2); i++) {
        prefix[i] = '\0';
    }

    for (i=0; i<len; i++) {
        if ((infix[i] == ' ') || (infix[i] == '\t')) {
            continue;
        }

        if(isalnum(infix[i])) {
            prefix[j] = infix[i];
            j++;
        } else if(is_operator(infix[i])) {
            if (top == -1) {
                stack[++top] = infix[i];
            } else {
                while((precedence(stack[top]) >= precedence(infix[i])) && (top != -1)) {
                    prefix[j] = stack[top];
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
                prefix[j] = stack[top];
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
        prefix[j] = stack[top];
        j++;
        top--;
    }

    prefix[j] = '\0';

    reverse_string(prefix);

    return prefix;
}

int main()
{
    char infix[100], *prefix;
    
    printf("Enter an expression: ");
    scanf("%s", infix);

    prefix = infix_to_prefix(infix);

    printf("The prefix expression is: %s", prefix);

    free(prefix);
}