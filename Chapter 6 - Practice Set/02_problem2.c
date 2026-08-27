#include <stdio.h>


int returning_5(int* ptr){
    printf("The value of ptr is %d\n", /* ?? */); 
    printf("The value at ptr is %d\n", /* ?? */); 
    return 5;
}
int main(){
    int i = 2;
    int* ptr = &i;
    printf("The address of i is %u\n", /* ?? */); 
    returning_5(ptr);
    return 0;
}