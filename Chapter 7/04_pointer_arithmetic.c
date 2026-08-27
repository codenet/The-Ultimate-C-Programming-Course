#include <stdio.h>

int main(){

    // POINTER ARITHMETIC USING INTEGER POINTER
    int a = 5;
    int *ptr = &a;
    printf("The address of a is %p\n", &a);
    printf("The address of a is %p\n", ptr);
    ptr++;
    printf("The value of ptr is %p\n", ptr);

    // POINTER ARITHMETIC USING CHARACTER POINTER
    char c = 'A';
    char *cptr = &c;
    printf("The address of c is %p\n", &c);
    printf("The address of c is %p\n", cptr);
    cptr++;
    printf("The value of cptr is %p\n", cptr);
    return 0;
}
