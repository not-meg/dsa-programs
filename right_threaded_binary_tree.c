#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int rthread;
};

struct node * create_new(int d)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = d;
    new->left = NULL;
    new->right = NULL;
    new->rthread = 1;

    return new;
}

void create_tree(struct node **root)
{
    int d, n, i;
    struct node *p;
    struct node *q;

    printf("Enter the data of the root: ");
    scanf("%d", &d);
    fflush(stdin);

    *root = create_new(d);
    (*root)->rthread = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    fflush(stdin);

    for(i=0; i<n; i++) {
        printf("Enter data: ");
        scanf("%d", &d);
        fflush(stdin);

        struct node *new = create_new(d);

        p = *root;

        while(p != NULL) {
            if(d < p->data) {
                if(p->left == NULL) {
                    p->left = new;
                    new->right = p;
                    break;
                } else {
                    p = p->left;
                }
            } else {
                if(p->right == NULL) {
                    p->right = new;
                    p->rthread = 0;
                    break;
                } else {
                    if(p->rthread == 1)
                    {
                        new->right = p->right;
                        p->right = new;
                        p->rthread = 0;
                        break;
                    } else {
                        p = p->right;
                    }
                    
                }
            }
        }
    }
}

void display(struct node *root)
{

    if(root == NULL) {
        return;
    }
    struct node *temp = root;


    if(temp->left == NULL) {
        printf("%d\t", temp->data);
        temp = temp->right;
        printf("%d\t", temp->data);
        display(temp->right);
        return;
    } else {
        if(temp->right != NULL) {
            display(temp->left);
        }
        
    }
}

int main()
{
    struct node *root = NULL;

    create_tree(&root);

    display(root);
}