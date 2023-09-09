#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    char symb;
    struct node *next;
};

void push(struct node **top, char c)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    
    new->symb = c;
    new->next = *top;
    *top = new;
}

char pop(struct node **top)
{
    struct node *temp = *top;
    char d = temp->symb;

    *top = temp->next;

    free(temp);

    return d;
}

int check_operator(char c)
{
    switch(c) {
        case '+':
            return 1;

        case '-':
            return 2;
        
        case '*':
            return 3;

        case '/':
            return 4;

        case '^':
            return 5;

        default:
            return -1;
    }
}


void free_stack(struct node **top)
{
    struct node *temp = *top;

    while(temp != NULL) {
        *top = temp->next;
        free(temp);
        temp = *top;
    }
    *top = NULL;
}

void push_opening_bracket(struct node *top, char c)
{
    push(&top, c);
}

void check_closing_bracket(struct node *top, int *count)
{
    int temp;
   if (*count == 0) {
        printf("Invalid expression.\n");
        free_stack(&top);
        exit(-1);
    }
    (*count)--;
    temp = pop(&top);
    pop(&top);
    push(&top, temp); 
}

int postfix_eval(char *postfix)
{
    struct node *top = NULL;

    int i=0, len=strlen(postfix), operator_type, operand, op1, op2, temp, result, count_round=0, count_curly=0, count_square=0;
    char str[2];

    for(i=0; i<len; i++) {
        if (isalnum(postfix[i])) {
            str[0] = postfix[i];
            str[1] = '\0';
            operand = atoi(str);
            printf("Operand = %d\n", operand);
            push(&top, operand);
        } else {
            if (postfix[i] == '(') {
                count_round++;
                push_opening_bracket(top, postfix[i]);
            } else if (postfix[i] == ')') {
                check_closing_bracket(top, count_round);

            } else if(postfix[i] == '{') {
                count_curly++;
                push_opening_bracket(top, postfix[i]);
            } else if (postfix[i] == '}') {
                check_closing_bracket(top, count_curly);

            } else if (postfix[i] == '[') {
                count_square++;
                push_opening_bracket(top, postfix[i]);
            } else if (postfix[i] == ']') {
                check_closing_bracket(top, count_square);

            } else {
                operator_type = check_operator(postfix[i]);
                op2 = pop(&top);
                op1 = pop(&top);

                printf("op1 = %d\nop2 = %d\n", op1, op2);

                switch(operator_type) {
                    case 1:
                        temp = op1 + op2;
                        push(&top, temp);
                        break;
                    case 2:
                        temp = op1 - op2;
                        push(&top, temp);
                        break;
                    case 3:
                        temp = op1 * op2;
                        push(&top, temp);
                        break;
                    case 4:
                        temp = op1 / op2;
                        push(&top, temp);
                        break;
                    case 5:
                        temp = op1 ^ op2;
                        push(&top, temp);
                        break;
                    default:
                        printf("Invalid operator.\n");
                        free_stack(&top);
                        exit(-1);
                }
            }
            
        }  
    }
    result = pop(&top);

    if(top != NULL) {
        printf("Invalid expression at end.\n");
        exit(-1);
    }

    return result;
}

int main()
{
    char postfix[100];
    int result;

    printf("Enter a postfix expression: ");
    scanf("%s", &postfix);

    result = postfix_eval(postfix);

    printf("The result is: %d\n", result);
}