#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int * top_down(int *a, int n)
{
    int i, ele, p, c;

    for(i=1; i<n; i++) {
        ele = a[i];
        c = i;
        p = (c - 1)/2;

        while((c>0) && (ele>a[p])) {
            a[c] = a[p];
            c = p;
            p = (c-1)/2;
        }

        a[c] = ele;
    }

    return a;
}

void display(int *a, int n)
{
    int i;

    for(i=0; i<n; i++) {
        printf("%d\t", a[i]);
    }

    printf("\n");
}

int main()
{
    int a[MAX], n, i, *res;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }

    res = top_down(a, n);

    display(res, n);
}