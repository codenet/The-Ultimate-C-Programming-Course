#include <stdio.h>

int main(){
    int i = 2;
    int* ptr1 = &i;
    int** ptr2 = &ptr1;
    printf("The address of i is %u\n", &i);
    // Print value of i using just ptr1
    // Print value of i using just ptr2
    return 0;
}