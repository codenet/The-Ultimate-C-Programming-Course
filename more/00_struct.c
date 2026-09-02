// gcc struct.c -lm
#include<stdio.h>
#include<math.h>

// pack changes the size of struct from 12 to 9.
// Without pack, the struct has to be 4-byte aligned (largest member int is 4-bytes)
#pragma pack(1)
struct Point {
	int x, y;
	char name;
};

typedef struct Point Point;

// float distance(int p1x, int p1y, int p2x, int p2y) {
// 	return sqrt(pow(p1x - p2x, 2) + pow(p1y - p2y, 2));
// }

float distance(Point p1, Point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
	Point p1 = {.x = 0, .y = 0, .name='a'};
	Point p2 = {.x = 3, .y = 4, .name='b'};

	printf("distance betwen %c and %c is %.2f\n", p1.name, p2.name, distance(p1, p2));
	printf("%lu %lu %lu\n", sizeof(p1), sizeof(p1.x), sizeof(int));
	printf("p1  : %p\np1.x: %p\np1.y: %p\n", &p1, &(p1.x), &(p1.y));
}
