#include <stdio.h>

int main() {
    // %z means we are printing a size
    // %u means it is an unsigned number
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of char: %zu byte\n", sizeof(char));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    return 0;
}
