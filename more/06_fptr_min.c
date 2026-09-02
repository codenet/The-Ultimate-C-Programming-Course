#include<stdio.h>
#include<stdlib.h>
#define SZ 10

struct Circle {
	int x, y, r;
};

typedef struct Circle Circle;

void* x_comp(void* v1, void* v2) {
	Circle* c1 = (Circle*) v1;
	Circle* c2 = (Circle*) v2;
	if(c1->x <= c2->x)
		return c1;
	return c2;
}

void* y_comp(void* v1, void* v2) {
	Circle* c1 = (Circle*) v1;
	Circle* c2 = (Circle*) v2;
	if(c1->y - c1->r <= c2->y - c2->r)
		return c1;
	return c2;
}

void* min_fptr(void* circles[SZ], void* (*comp)(void*, void*)) {
	void* min = circles[0];
	// printf("Assigning min to 0\n");
	for(int i = 1; i < SZ; i ++)
		min =  comp(circles[i], min);
	return min;
}

Circle* min(Circle* circles[SZ]) {
	Circle* min = circles[0];
	for(int i = 1; i < SZ; i ++)
		// if(circles[i]->x < min->x) {
		// if(circles[i]->y < min->y) {
		if(circles[i]->r < min->r) {
			min =  circles[i];
		}
	return min;
}

int main() {
	Circle circles[SZ];
	void* pcircles[SZ];
	for(int i = 0 ; i < SZ; i ++) {
		circles[i].x  = rand()%SZ;
		circles[i].y  = rand()%SZ;
		circles[i].r  = rand()%SZ;
		pcircles[i] = (void*) &circles[i];
		printf("Circle %d: center (%d, %d) radius %d\n", i, circles[i].x, circles[i].y, circles[i].r);
	}

	Circle* left = min(pcircles);
	printf("Output circle: center (%d, %d) radius %d\n", left->x, left->y, left->r);

	Circle* smallest_x = min_fptr(pcircles, x_comp);
	printf("circle with minimum x in center: center (%d, %d) radius %d\n", smallest_x->x, smallest_x->y, smallest_x->r);

	Circle* smallest_y = min_fptr(pcircles, y_comp);
	printf("circle with minimum y point: center (%d, %d) radius %d\n", smallest_y->x, smallest_y->y, smallest_y->r);

	// 2. Spot the error
	for(int i = 0 ; i < SZ; i ++) {
		Circle circle;
		circle.x  = rand()%SZ;
		circle.y  = rand()%SZ;
		circle.r  = rand()%SZ;
		circles[i] = circle;
		printf("Circle %d: center (%d, %d) radius %d\n", i, circles[i].x, circles[i].y, circles[i].r);
	}

	Circle* smallest = min(circles);
	printf("Output circle: center (%d, %d) radius %d\n", smallest->x, smallest->y, smallest->r);
}
