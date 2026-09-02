#include <stdio.h>

void swap_v(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a = 4, b = 6;
    printf("The value of a is %d and the value of b is %d\n", a, b);

    swap_v(a, b);
    printf("The value of a is %d and the value of b is %d\n", a, b);

    swap(&a, &b);
    printf("The value of a is %d and the value of b is %d\n", a, b);
    return 0;
}
