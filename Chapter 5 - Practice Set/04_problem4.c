#include <stdio.h>

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
int fibonacci(int);

// Write recursive function to calculate fibonacci
 
int main(){
    int n = 7;
    printf("The value of fibonacci series at %d is %d", n, fibonacci(n));
    return 0;
}