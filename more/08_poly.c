#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Shape {
    float (*area)(struct Shape*);
    float (*perimeter)(struct Shape*);
} Shape;

// Circle
typedef struct {
    Shape base;
    float x, y, r;
} Circle;

float circle_area(Shape* s) {
    Circle* c = (Circle*)s;
    return 22.0 * c->r * c->r / 7;
}

float circle_perimeter(Shape* s) {
    Circle* c = (Circle*)s;
    return 2 * 22.0 * c->r / 7;
}

Circle* cir_init(float x, float y, float r) {
    Circle* c = (Circle*)malloc(sizeof(Circle));
    c->x = x; c->y = y; c->r = r;
    c->base.area = circle_area;
    c->base.perimeter = circle_perimeter;
    return c;
}

// Rectangle
typedef struct {
    Shape base;
    float x1, y1, x2, y2;
} Rect;

float rect_area(Shape* s) {
    Rect* r = (Rect*)s;
    return (r->x2 - r->x1) * (r->y2 - r->y1);
}

float rect_perimeter(Shape* s) {
    Rect* r = (Rect*)s;
    return 2 * (r->x2 - r->x1) + 2 * (r->y2 - r->y1);
}

Rect* rect_init(float x1, float y1, float x2, float y2) {
    Rect* r = (Rect*)malloc(sizeof(Rect));
    r->x1 = x1; r->y1 = y1; r->x2 = x2; r->y2 = y2;
    r->base.area = rect_area;
    r->base.perimeter = rect_perimeter;
    return r;
}

int main() {
    Shape* c1 = (Shape*)cir_init(0, 0, 5);
    Shape* r1 = (Shape*)rect_init(0, 0, 10, 10);

    printf("Circle area, circumference: %.2f %.2f\n", c1->area(c1), c1->perimeter(c1));
    printf("Rectangle area, perimeter: %.2f %.2f\n", r1->area(r1), r1->perimeter(r1));

		printf("c1: %lu r1: %lu\n", sizeof(c1), sizeof(r1));
		printf("*c1: %lu *r1: %lu\n", sizeof(*c1), sizeof(*r1));


    Circle* c = (Circle*)c1;
    Rect* r = (Rect*)r1;
		printf("*c: %lu *r: %lu\n", sizeof(*c), sizeof(*r));	// prints 32, 32 for aligning Circle
    return 0;
}