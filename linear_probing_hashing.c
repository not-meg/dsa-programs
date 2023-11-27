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
    if (hash_table[location].occupied == 0) {
        hash_table[location].data = ele;
        hash_table[location].occupied = 1;
    } else {
        int j = 1;
        while (j < n) {
            int new_location = (location + j) % n;
            if (check_location(hash_table, new_location)) {
                hash_table[new_location].data = ele;
                hash_table[new_location].occupied = 1;
                return;
            }
            j++;
        }
    }
}

int search_element(struct node *hash_table, int n, int ele)
{
    int location = ele % n;
    int j = 0;

    while (j < n) {
        int new_location = (location + j) % n;
        if (hash_table[new_location].occupied == 1 && hash_table[new_location].data == ele) {
            return 1;
        }
        j++;
    }
    return 0;
}

void delete_element(struct node *hash_table, int n, int ele)
{
    int location = ele % n;
    int j = 0;

    while (j < n) {
        int new_location = (location + j) % n;
        if (hash_table[new_location].occupied == 1 && hash_table[new_location].data == ele) {
            hash_table[new_location].occupied = 0;
            return;
        }
        j++;
    }
}

int main()
{
    struct node hash_table[MAX];
    int q, operation, ele, result;

    scanf("%d", &q);

    for(int i = 0; i < MAX; i++) {
        hash_table[i].occupied = 0;
    }

    for(int i = 0; i < q; i++) {
        scanf("%d %d", &operation, &ele);

        switch (operation) {
            case 1:
                add_element(hash_table, MAX, ele % MAX, ele);
                break;
            case 2:
                result = search_element(hash_table, MAX, ele);
                printf(result ? "true\n" : "false\n");
                break;
            case 3:
                delete_element(hash_table, MAX, ele);
                break;
            default:
                return -1;
        }
    }

    return 0;
}