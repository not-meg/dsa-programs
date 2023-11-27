#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node
{
    int data;
    int occupied;
};

int location_free(struct node hash_table[MAX], int location)
{
    if (hash_table[location].occupied == 0) {
        return 1;
    } else {
        return 0;
    }
}

void insertion(struct node hash_table[MAX], int data, int location)
{
    hash_table[location].occupied = 1;
    hash_table[location].data = data;
    return;
}

int main()
{
    struct node hash_table[MAX];

    int data, n, i, j, location, new_location;

    printf("Enter the size of the hash table: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter the data: ");
        scanf("%d", &data);

        location = data % n;

        for(j=0; j<n; j++) {
            new_location = (location + j*(data % 7)) % n;

            if(location_free(hash_table, new_location)) {
                insertion(hash_table, data, new_location);
                break;
            }
        }
        
        if(!location_free(hash_table, location)) {
            printf("Cannot insert.\n");
        }
    }

    return 0;
}
