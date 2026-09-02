#include <stdio.h>
#include <stdlib.h>

// void* malloc(size_t sz);

int main(){
    int n;
    int* ptr;
    scanf("%d", &n);

		// Dynamic memory allocation
    ptr = (int*) malloc(n * sizeof(int));
    // int arr[n]; // Not allowed in c
    ptr[0] = 3;
    ptr[1]= 6;
    printf("%d\n", ptr[0]);
    return 0;
}
