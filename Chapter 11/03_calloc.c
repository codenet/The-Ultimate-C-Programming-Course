#include <stdio.h>
#include <stdlib.h>

int main(){
	int n=100;
	int* ptr;

	ptr = (int*) calloc(n, sizeof(int));
	for(int i=0; i<n; i++)
		printf("%d", ptr[i]);
	printf("\n");

	ptr = (int*) malloc(n * sizeof(int));
	for(int i=0; i<n; i++)
		printf("%d", ptr[i]);
	printf("\n");

	return 0;
}
