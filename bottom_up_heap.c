#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void bottom_up(int *a, int n) {
    int k, i, p, c, ele;

    k = n/2 - 1;

    for(i=k; i>=0; i--) {
        p = i;
        c = 2*p + 1;
        ele = a[p];

        while(c < n) {
            if(c+1 < n && a[c] < a[c+1]) {
                c = c+1;
            }

            if(ele >= a[c]) {
                break;
            }

            a[p] = a[c];
            p = c;
            c = 2*p + 1;
        }

        a[p] = ele;
    }
}

void display(int *a, int n) {
    int i;

    for(i=0; i<n; i++) {
        printf("%d\t", a[i]);
    }

    printf("\n");
}

int main() {
    int a[MAX];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter the element ");
        scanf("%d", &a[i]);
    }

    bottom_up(a, n);

    display(a, n);

    return 0;
}
