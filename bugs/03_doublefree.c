#include<stdio.h>
#include<stdlib.h>
int main() {
	char* x = (char*) malloc(10*sizeof(char));
	printf("x: %p\n", x);
	x[9] = 0;
	for(int i=0; i < 9; i++) {
		x[i] = 'x';
	}
	free(x);

	char* y = (char*) malloc(10*sizeof(char));
	printf("y: %p\n", y);
	y[9] = 0;
	for(int i=0; i < 9; i++) {
		y[i] = 'y';
	}
	// free(x);

	char* z = (char*) malloc(10*sizeof(char));
	printf("z: %p\n", z);
	z[9] = 0;
	for(int i=0; i < 9; i++) {
		z[i] = 'z';
	}

	y[3] = 'Y';

	printf("%s\n", y);
}

// gcc -g doublefree.c
// gdb ./a.out
// b doublefree.c:12
// r
// > x: 0x5555555592a0
// watch *(char*)0x5555555592a0
// > Hardware watchpoint 2: *(char*)0x5555555592a0
// c
// > Hardware watchpoint 2: *(char*)0x5555555592a0
// > Old value = 0 '\000'
// > New value = 121 'y'
// > main () at doublefree.c:15
// c
// > Hardware watchpoint 2: *(char*)0x5555555592a0
// > Old value = 121 'y'
// > New value = 0 '\000'
// > tcache_put (tc_idx=0, chunk=0x555555559290) at malloc.c:2927
// c
// > Hardware watchpoint 2: *(char*)0x5555555592a0
// > Old value = 0 '\000'
// > New value = 122 'z'
// > main () at doublefree.c:23
