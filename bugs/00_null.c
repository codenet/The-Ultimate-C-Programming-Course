#include<stdio.h>
#include<stddef.h>
int main() {
	int* x = NULL;
	printf("x: %d\n", *x);
}

// gcc -g null.c
// gdb a.out
// (gdb) r
// Starting program: a.out
// 
// Program received signal SIGSEGV, Segmentation fault.
// 0x0000555555555161 in main () at null.c:5
// (gdb) print x
// $1 = (int *) 0x0
