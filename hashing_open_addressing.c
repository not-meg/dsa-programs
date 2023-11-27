#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node
{
    int data;
    int occupied;
};

int check_location(struct node hash_table[MAX], int location)
{
    if(hash_table[location].occupied == 0) {
        return 1;
    } else {
        return 0;
    }
}

void add_element(struct node *hash_table, int n, int location, int ele)
{
    hash_table[location].data = ele;
    hash_table[location].occupied = 1;
}

void display(struct node hash_table[MAX], int n)
{
    int i;

    for(i=0; i<n; i++) {
        printf("%d\n", hash_table[i].data);
    }
}

int main()
{
    struct node hash_table[MAX];
    int n, location, i, ele, j, new_location;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        hash_table[i].occupied = 0;
    }

    for(i=0; i<n; i++) {
        printf("Enter the element: ");
        scanf("%d", &ele);

        location = ele % n;
        new_location = location;

        j = 0;

        while (!check_location(hash_table, new_location)) {
            new_location = (location + j) % n;
            j++;
        }

        add_element(hash_table, n, new_location, ele);
    }


    display(hash_table, n);
}