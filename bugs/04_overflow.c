// Disable ASLR to see overflow
// setarch `uname -m` -R /bin/bash
#include<stdio.h>
#include<stdlib.h>

int main() {
	int* x = (int*) malloc(sizeof(int) * 100);
	int* y = (int*) malloc(sizeof(int));
	// printf("%p %p\n", x, y);
	*y = 23;
	for(int i=0; i < 105; i++)
		x[i] = 0;
	// x[104] = 0;
	printf("y: %d\n", *y);
}

// gdb a.out
// (gdb) b overflow.c:9
// (gdb) print y
// $1 = (int *) 0x555555559440
// (gdb) watch *(int*) 0x555555559440
// Hardware watchpoint 2: *(int*) 0x555555559440
// (gdb) c
// Continuing.
// 
// Hardware watchpoint 2: *(int*) 0x555555559440
// 
// Old value = 0
// New value = 23
// main () at overflow.c:11
// (gdb) c
// Continuing.
// 
// Hardware watchpoint 2: *(int*) 0x555555559440
// 
// Old value = 23
// New value = 0
// main () at overflow.c:11
// (gdb) print i
// $2 = 104
