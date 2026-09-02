#include<stdio.h>
#include<time.h>
#define SZ 2*1024*1024
#define ITER 10

typedef struct {
	char x[SZ];
} big;

void val(big b) {
	printf("val &b: %p\n", &b);
}

void ref(big* b) {
	printf("ref &b: %p\n", b);
}

int main() {
	big b;
	printf("main &b: %p\n", &b);
	time_t start = clock();
	for(int i = 0; i < ITER; i ++)
		val(b);
	time_t end = clock();
	double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Time in call by value: %.8f\n", elapsed);

	start = clock();
	for(int i = 0; i < ITER; i ++)
		ref(&b);
	end = clock();
	elapsed = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Time in call by ref: %.8f\n", elapsed);
}
