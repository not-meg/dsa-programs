#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node * create_new(int d)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->prev = NULL;
    new->next = NULL;
    new->data = d;

    return new;
}

void insertion_front(struct node **head, int d)
{
    struct node *new = create_new(d);

    if (*head == NULL) {
        *head = new;
    } else {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
}

void insertion_back(struct node **head, int d)
{
    struct node *new = create_new(d);

    if (*head == NULL) {
        *head = new;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}

void display(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int deletion_front(struct node **head)
{
    if (*head == NULL) {
        return -1;
    }

    struct node *temp = *head;
    *head = temp->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    int d = temp->data;
    free(temp);

    return d;
}

int deletion_back(struct node **head)
{
    if (*head == NULL) {
        return -1;
    }

    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    int d = temp->data;
    free(temp);

    return d;
}

void delete_list(struct node **head)
{
    if(*head == NULL) {
        return;
    }

    struct node *temp = *head;
    struct node *next;

    while(temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
}

int main()
{
    struct node *head = NULL;
    int n, d, i;

    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the data to be inserted: ");
        scanf("%d", &d);

        insertion_front(&head, d);
    }

    display(head);

    printf("Enter the number of elements to be deleted: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        d = deletion_back(&head);

        if (d != -1) {
            printf("Element deleted: %d\n", d);
        }
    }

    display(head);

    delete_list(&head);

    return 0;
}