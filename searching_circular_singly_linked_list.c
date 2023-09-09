#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int count = 0;

struct node * create_node(int d)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = d;
    new->next = NULL;
}

void insertion(struct node **tail, int d)
{
    struct node *new = create_node(d);
    
    count++;

    if(*tail == NULL) {
        *tail = new;
        new->next = new;
        return;
    }

    new->next = (*tail)->next;
    (*tail)->next = new;
    return;
}

int search_data(struct node *tail, int d)
{
    int pos = 0;
    struct node *temp = tail->next;


    while(temp != tail) {
        if(temp->data == d) {
            return pos;
        }
        pos++;
        temp = temp->next;
    }

    if(temp == tail) {
        if(temp->data == d) {
            return pos;
        }
    }
    return -1;
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

int search_position(struct node **tail, int pos)
{
    if(pos > (count-1)) {
        return -1;
    }

    struct node *temp = (*tail)->next;
    int i;

    for(i=0; i<pos; i++) {
        temp = temp->next;
    }

    return temp->data;
}

int main()
{
    struct node *tail = NULL;
    int n, d, i, pos;

    printf("Enter number of nodes to be inserted: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter data to be inserted: ");
        scanf("%d", &d);
        insertion(&tail, d);
    }

    display(tail);

    printf("Enter the data to be searched: ");
    scanf("%d", &d);

    pos = search_data(tail, d);

    if(pos != -1) {
        printf("Data found at position %d\n", pos);
    } else {
        printf("Data not found.\n");
    }

    /*printf("Enter the position to find the data: ");
    scanf("%d", &pos);

    d = search_position(&tail, pos);

    if(d != -1) {
        printf("Data found: %d", d);
    } else {
        printf("Data not found.\n");
    }*/
}