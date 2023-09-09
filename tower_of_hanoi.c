#include <stdio.h>

void tower(int n, char from, char aux, char to)
{
    printf("n = %d\tfrom = %c\taux = %c\tto = %c\n\n\n", n, from, aux, to);
    if (n == 1) {
        printf("Move rod %d from %c to %c\n", n, from, to);
        return;
    }

    tower(n-1, from, to, aux);
    printf("--Move rod %d from %c to %c\n", n, from, to);
    tower(n-1, aux, from, to);
}

int main()
{
    char from = 'a', aux = 'b', to = 'c';
    int n;

    printf("Enter number of rods: ");
    scanf("%d", &n);

    tower(n, from, aux, to);
}