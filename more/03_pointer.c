#include<stdio.h>

int main() {
	int x, y; 
	int *p1, *p2; 
	x = 2, y = 3;
	printf("x: %d, y: %d\n", x, y);

	p1 = &x, p2 = &y;
	*p1 = 5; 
	*p2 = 8;
	printf("x: %d, y: %d\n", x, y);

	int **p = &p2;
	*p = p1;
	*p2 = 10;
	printf("x: %d, y: %d\n", x, y);	// 5, 10 or 10, 10 or 10, 8?

	printf("%lu, %lu, %lu, %lu\n", sizeof(x), sizeof(y), sizeof(p1), sizeof(p2));
}
