#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int count = 0;

struct node * create_node(int d)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = d;
    new->prev = NULL;
    new->next = NULL;

    return new;
}

void insertion_front(struct node **head, int d)
{
    struct node *new = create_node(d);

    count++;

    if(*head == NULL) {
        new->next = new;
        new->prev = new;
        *head = new;
        return;
    }

    new->next = *head;
    (*head)->prev->next = new;
    new->prev = (*head)->prev;
    (*head)->prev = new;
    *head = new;
}

int deletion_front(struct node **head)
{
    if(*head == NULL) {
        return -1;
    }

    int d;
    struct node *temp = *head;

    count--;

    if((*head)->next == *head) {
        d = temp->data;
        free(temp);
        *head = NULL;
        return d;
    }

    d = temp->data;

    (*head)->prev->next = (*head)->next;
    (*head)->next->prev = (*head)->prev;
    free(temp);
    *head = (*head)->next;

    return d;
}

void insertion_back(struct node **head, int d)
{
    struct node *new = create_node(d);

    count++;

    if(*head == NULL) {
        new->next = new;
        new->prev = new;
        *head = new;
        return;
    }

    new->prev = (*head)->prev;
    (*head)->prev->next = new;
    (*head)->prev = new;
    new->next = *head;
}

int deletion_back(struct node **head)
{
    if(*head == NULL) {
        return -1;
    }

    int d;
    struct node *temp = (*head)->prev;

    count--;

    if((*head)->next == *head) {
        d = temp->data;
        free(temp);
        *head = NULL;
        return d;
    }

    d = temp->data;

    (*head)->prev = (*head)->prev->prev;
    (*head)->prev->next = *head;

    free(temp);

    return d;
}

void insertion_pos(struct node **head, int d, int pos)
{
    if((pos > (count+1)) || (pos < 0)) {
        printf("Invalid position.\n");
        return;
    }
    if(pos == 0) {
        insertion_front(head, d);
    } else if (pos == (count+1)) {
        insertion_back(head, d);
    }

    struct node *temp = *head;
    struct node *bef = NULL;
    int i;

    struct node *new = create_node(d);

    count++;

    for(i=0; i<pos; i++) {
        bef = temp;
        temp = temp->next;
    }

    new->next = bef->next;
    bef->next = new;
    new->prev = bef;
    new->next->prev = new;
}

int deletion_pos(struct node **head, int pos)
{
    int d;

    if((count < 0) || (count > (count+1))) {
        printf("Invalid positon.\n");
        return -1;
    } else if (pos == 0) {
        d = deletion_front(head);
        return d;
    } else if (pos == count+1) {
        d = deletion_back(head);
        return d;
    }

    struct node *temp = *head;
    struct node *bef = NULL;
    int i;

    for(i=0; i<pos; i++) {
        bef = temp;
        temp = temp->next;
    }

    bef->next = temp->next;
    temp->next->prev = bef;

    d = temp->data;
    free(temp);

    return d;
}

void display(struct node *head)
{
    if(head == NULL) {
        return;
    }

    struct node *temp = head;

    while(temp->next != head) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);

    printf("\n");
}

int main()
{
    struct node *head = NULL;

    int n, d, i, pos;

    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter the data to be inserted: ");
        scanf("%d", &d);

        insertion_back(&head, d);
    }

    display(head);

    /*printf("Enter the number of elements to be deleted: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        d = deletion_back(&head);

        if(d != -1) {
            printf("Deleted element: %d\n", d);
        }
    }

    display(head);*/

    printf("Enter the position to insert data: ");
    scanf("%d", &pos);

    printf("Enter the data to be inserted: ");
    scanf("%d", &d);

    insertion_pos(&head, d, pos);

    display(head);

    printf("Enter the position to delete data: ");
    scanf("%d", &pos);

    d = deletion_pos(&head, pos);

    if(d != -1) {
        printf("Deleted element: %d\n", d);
    }

    display(head);
}