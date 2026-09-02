#include <stdio.h>

int main(){
    int marks[5] = {1, 2, 3, 4, 5};  

      for (int i = 0; i < 5; i++)
    {
        printf("The address of marks at index %d is %p\n", i, &marks[i]);	// separated by 4
    }
    
 
    return 0;
}
