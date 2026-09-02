#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=100;
    int* ptr;
    ptr = (int*) malloc(n * sizeof(int));
    ptr[0] = 3; 
    free(ptr);
    printf("%d\n", ptr[0]);	// Free just tells the allocator. Does not write 0s on the freed memory
    return 0;
}
