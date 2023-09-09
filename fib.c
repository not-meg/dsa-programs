#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int n) {
    if (n < 0) {
        printf("Invalid input.\n");
        return -1;
    }

    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Fibonacci sequence up to %d:\n", n);
    for (i = 0; i <= n; i++) {
        int result = fibonacci(i);
        printf("%d\n", result);
    }

    return 0;
}