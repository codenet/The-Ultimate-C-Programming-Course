#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

#define CIRCLE 0
#define RECTANGLE 1

#define false 0

struct Circle {
	float x, y, r;
};

struct Rect {
	float x1, y1, x2, y2;
};

struct Shape {
	int shapeType;
	union {
		struct Circle c;
		struct Rect r;
	} s;
};


struct Shape* cir_init(float x, float y, float r) {
	struct Shape* shape = (struct Shape*) malloc(sizeof(struct Shape));
	struct Circle *c = &(shape->s.c);
	c->x = x; c->y = y; c->r = r;
	shape->shapeType = CIRCLE;
	return shape;
}

float area(struct Shape shape) {
	if (shape.shapeType == CIRCLE) {
		struct Circle c = shape.s.c;
		return 22.0 * c.r * c.r / 7;
	} else if (shape.shapeType == RECTANGLE) {
		struct Rect r = shape.s.r;
		return (r.x2-r.x1) * (r.y2-r.y1);
	}
	fprintf(stderr, "Unexpected shapeType: %d\n", shape.shapeType);
	assert(false);
	return -1;
}

float perimeter(struct Shape shape) {
	if (shape.shapeType == CIRCLE) {
		struct Circle c = shape.s.c;
		return 2 * 22.0 * c.r / 7;
	} else if (shape.shapeType == RECTANGLE) {
		struct Rect r = shape.s.r;
		return 2*(r.x2-r.x1) + 2*(r.y2-r.y1);
	}
	fprintf(stderr, "Unexpected shapeType: %d\n", shape.shapeType);
	assert(false);
	return -1;
}

struct Shape* rect_init(float x1, float x2, float y1, float y2) {
	struct Shape* shape = (struct Shape*) malloc(sizeof(struct Shape));
	struct Rect *r = &(shape->s.r);
	r->x1 = x1; r->y1 = y1; r->x2 = x2; r->y2 = y2;
	shape->shapeType = RECTANGLE;
	return shape;
}

int main() {
	struct Shape* c1 = cir_init(0,0,5);
	struct Shape* r1 = rect_init(0,10,0,10);

	printf("Circle area, circumference: %.2f %.2f\n", area(*c1), perimeter(*c1));
	printf("Rectangle area, perimeter: %.2f %.2f\n", area(*r1), perimeter(*r1));
	printf("Size of int: %lu, float: %lu, Circle: %lu, Rectange: %lu, Shape: %lu\n", 
			sizeof(int), sizeof(float), sizeof(struct Circle), sizeof(struct Rect), sizeof(*c1));
}
