#include<stdio.h>
#include<stdlib.h>
int main() {
	char* x = (char*) malloc(10*sizeof(char));
	free(x);

	char* y = (char*) malloc(10*sizeof(char));
	y[9] = 0;
	for(int i = 0; i < 9; i++)
		y[i] = 'y';

	x[8] = 'x';
	printf("y: %s\n", y);
}
