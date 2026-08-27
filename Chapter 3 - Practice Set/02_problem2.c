#include <stdio.h>

int main(){
    int marks1, marks2, marks3;
    printf("Enter marks1: \n");
    scanf("%d", &marks1);
    printf("Enter marks2: \n");
    scanf("%d", &marks2);
    printf("Enter marks3: \n");
    scanf("%d", &marks3);
    printf("The marks are %d %d and %d\n", marks1, marks2, marks3);

    // Print following if marks are below 33 in any subject
    // You have failed due to less than 33 marks in a subject(s)

    // Print following if total percentage is below 40
    // You have failed due less percentage

    // Otherwise print 
    // You are passed!
    return 0;
}