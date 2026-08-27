#include <stdio.h>

void change_to_ten_times(int a){
    a = a * 10;
}

int main(){
    int x = 45;
    printf("The value of x is %d\n", x);
    change_to_ten_times(x);
    // Guess what will be the value of x without running the program.
    // Run the program and see if your guess was right
    // Fix the program
    printf("The value of x is %d\n", x);

    return 0;
}