#include<stdio.h>
#include <stdlib.h>

void fun1(int x)  {
	printf("fun1: %d\n", x);
}

void fun2(int x)  {
	printf("fun2: %d\n", x);
}

int main(int argc, char** argv) {
	void (*f_ptr)(int) =  &fun1;

	if(atoi(argv[1]) == 2)
		f_ptr = &fun2;

	(*f_ptr)(10);
	printf("size of f_ptr: %zu\n", sizeof(f_ptr));
}
