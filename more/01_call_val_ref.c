#include<stdio.h>

// ---------------
// |A|B|C|D|E|F|G|
// ---------------
// |3| | |3| | |A|
// ---------------
//  ^x    ^y    ^p

// Call by value
void foo_val(int y) {
	y = 3;
}

// call by reference 
void foo_ref(int *p) {
	*p = 3;	// const restrics modifying the pointed value
	// return (*p)*(*p);
}

int main() {
	int x = 2;

	foo_val(x);
	printf("x: %d\n", x);	// 2 or 3?

	foo_ref(&x);
	printf("x: %d\n", x); // 3?
}
