#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct hash_element
{
    int key;
    struct hash_element *next;
};

struct hash_element * create_node(int d)
{
    struct hash_element *new = (struct hash_element *)malloc(sizeof(struct hash_element));

    new->key = d;
    new->next = NULL;

    return new;
}

void create_hash_table(int ele, struct hash_element **hash_table, int n, int location)
{
    if (hash_table[location] == NULL) {
        hash_table[location] = create_node(ele);
        return;
    } else {
        struct hash_element *temp = hash_table[location];

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = create_node(ele);
        return;
    }
}

void display(struct hash_element *hash_table[MAX], int n)
{
    int i;

    struct hash_element *temp = NULL;

    for(i=0; i<n; i++) {
        temp = hash_table[i];

        while(temp != NULL) {
            printf("%d\t", temp->key);
            temp = temp->next;
        }

        printf("\n");
    }
}

int main()
{
    int n, i, location, ele;
    struct hash_element *hash_table[MAX];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid input for number of elements.\n");
        return 1;
    }

    for(i=0; i<n; i++) {
        hash_table[i] = NULL;
    }

    for(i=0; i<n; i++) {
        printf("Enter the element: ");
        scanf("%d", &ele);

        location = ele % n;

        create_hash_table(ele, &hash_table[0], n, location);
    }

    display(hash_table, n);

    for (i = 0; i < n; i++) {
        struct hash_element *temp = hash_table[i];
        while (temp != NULL) {
            struct hash_element *next = temp->next;
            free(temp);
            temp = next;
        }
    }

    return 0;
}