#include <stdio.h>


int* sum(int a, int b){
    int s = a+b;
    int* ptr = &s;
    printf("The sum is %d\n", s);
    return ptr;
}

float* average(int a, int b){
    float avg =  (a+b)/2.0;
    float * ptr = &avg;
    printf("The average is %f\n", avg);
    return ptr;
}

int main(){
    int x = 4; 
    int y = 6;
    int* ptr1;
    float* ptr2;

    ptr1 = sum(x,y);
    ptr2 = average(x,y);

    // Run this program and see if there is a problem with this program. fix it
    printf("The sum is %d and average is %f\n", *ptr1, *ptr2 );
    printf("The address of sum is %p and of average is %p\n", ptr1, ptr2 );

    return 0;
}