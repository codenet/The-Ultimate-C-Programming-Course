#include <stdio.h>

int main(){

    // POINTER ARITHMETIC USING INTEGER POINTER
    int a = 5;
    int *ptr = &a;
    printf("&a is %p\n", &a);
    printf("ptr is %p\n", ptr);
    ptr++;
    printf("The value of ptr is %p\n", ptr);	// increments by 4

    // POINTER ARITHMETIC USING CHARACTER POINTER
    char c = 'A';
    char *cptr = &c;
    printf("&c is %p\n", &c);
    printf("cptr is %p\n", cptr);
    cptr++;
    printf("The value of cptr is %p\n", cptr);	// increments by 1
    return 0;
}
