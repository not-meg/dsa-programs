#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * create_node(int d)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = d;
    new->next = NULL;

    return new;
}

void insertion_front(struct node **tail, int d)
{
    struct node *new = create_node(d);  

    if (*tail == NULL) {
        new->next = new;  
        *tail = new;
        return;
    }

    new->next = (*tail)->next;  
    (*tail)->next = new;        

}

void insertion_back(struct node **tail, int d)
{
    struct node *new = create_node(d);

    if (*tail == NULL) {
        new->next = new;
        *tail = new;
        return;
    }

    new->next = (*tail)->next;
    (*tail)->next = new;
    *tail = new;
}


void display(struct node *tail)
{
    if(tail == NULL) {
        return;
    }

    struct node *temp = tail->next;

    while(temp != tail) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);

    printf("\n");
}

int deletion_front(struct node **tail)
{
    if(*tail == NULL) {
        return -1;
    }
    
    struct node *temp = (*tail)->next;
    int d;

    if ((*tail)->next == NULL) {
        d = temp->data;
        free(temp);
        *tail = NULL;
        return d;
    }

    (*tail)->next = temp->next;
    d = temp->data;
    free(temp);
    return d;
}

int deletion_back(struct node **tail) {
    if (*tail == NULL) {
        return -1;
    }

    struct node *temp = (*tail)->next;
    int d;

    if (temp == *tail) {
        d = temp->data;
        free(temp);
        *tail = NULL;
        return d;
    }

    struct node *prev = *tail;

    while (prev->next != *tail) {
        prev = prev->next;
    }

    d = (*tail)->data;

    prev->next = temp;
    free(*tail);
    *tail = prev;
    return d;
}

int main()
{
    struct node *tail = NULL;
    int n, d, i;

    printf("Enter the number of nodes to be inserted: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter the data to be inserted: ");
        scanf("%d", &d);
        insertion_front(&tail, d);
    }

    display(tail);

    printf("Enter the number of nodes to be deleted: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        d = deletion_back(&tail);

        if(d != -1) {
            printf("Deleted data: %d\n", d);
        }
    }

    display(tail);
}