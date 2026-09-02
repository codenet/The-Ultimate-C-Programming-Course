#include <stdio.h>

float c2f(float);

// Create function definition of c2f

int main(){
    float c = 45;
    printf("Celsius to Fahrenheit for %f is %.2f", c, c2f(c));
    return 0;
}