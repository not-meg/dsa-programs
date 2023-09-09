#include <stdio.h>
#include <stdlib.h>

int count = 0;

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

void insertion_back(struct node **head, int d)
{
    struct node *new = create_node(d);

    count++;

    if(*head == NULL) {
        *head = new;
        new->next = *head;

        return;
    }

    struct node *temp = *head;

    while(temp->next != *head) {
        temp = temp->next;
    }

    new->next = *head;
    temp->next = new;
}

void insertion_front(struct node **head, int d)
{
    struct node *new = create_node(d);

    count++;

    if(*head == NULL) {
        *head = new;
        new->next = *head;
        
        return;
    }

    struct node *temp = *head;

    while(temp->next != *head) {
        temp = temp->next;
    }

    new->next = *head;
    temp->next = new;
    *head = new;
}

void insertion_pos(struct node **head, int d, int pos)
{
    if(pos == 0) {
        insertion_front(head, d);
        return;
    }

    if(pos > (count+1)) {
        printf("Invalid position.");
        return;
    }

    if(pos == (count+1)) {
        insertion_back(head, d);
        return;
    }

    int i;
    struct node *temp = *head;
    struct node *new = create_node(d);

    for(i=1; i<pos; i++) {
        temp = temp->next;
    }

    new->next = temp->next;
    temp->next = new;

    count++;
}

int deletion_back(struct node **head)
{
    if(*head == NULL) {
        return -1;
    }

    struct node *temp = *head;
    struct node *prev = NULL;
    int d;

    count--;

    if(temp->next == *head) {
        d = temp->data;
        free(temp);
        *head = NULL;
        return d;
    }

    while(temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    d = temp->data;

    prev->next = *head;
    free(temp);

    return d;
}

int deletion_front(struct node **head)
{
    if(*head == NULL) {
        return -1;
    }

    struct node *first = *head;
    int d;

    count--;

    if(first->next == *head) {
        d = first->data;
        free(first);
        *head = NULL;

        return d;
    }

    struct node *temp = *head;

    while(temp->next != *head) {
        temp = temp->next;
    }

    d = first->data;

    *head = first->next;
    temp->next = *head;

    return d;
}

int deletion_pos(struct node **head, int pos)
{
    int d, i;

    if(pos == 0) {
       d = deletion_front(head);
       return d; 
    }

    if(pos == (count+1)) {
        d = deletion_back(head);
        return d;
    }

    if (pos > (count+1)) {
        printf("Invalid position.\n");
        return -1;
    }

    struct node *temp = *head;
    struct node *prev = *head;

    for(i=0; i<pos; i++) {
        printf("here.\n");
        prev = temp;
        temp = temp->next;
    }

    d = temp->data;

    prev->next = temp->next;

    free(temp);

    return d;
}

void display(struct node *head)
{
    struct node *temp = head;

    if(head == NULL) {
        return;
    }

    while(temp->next != head) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("%d\n", temp->data);
}


int main()
{
    struct node *head = NULL;
    int n, d, i, pos;

    printf("Enter number of nodes to be inserted: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter data to be inserted: ");
        scanf("%d", &d);

        insertion_front(&head, d);
    }

    display(head);

    /*printf("Enter the number of nodes to be deleted: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        d = deletion_front(&head);

        if(d != -1) {
            printf("Deleted element: %d\n", d);
        }
    }

    display(head);*/

    /*printf("Enter the position to enter the element: ");
    scanf("%d", &pos);

    printf("Enter the element to be inserted: ");
    scanf("%d", &d);

    insertion_pos(&head, d, pos);

    display(head);*/

    printf("Enter the position to delete the element: ");
    scanf("%d", &pos);

    d = deletion_pos(&head, pos);

    if(d != -1) {
        printf("Deleted element: %d\n", d);
    }

    display(head);
}