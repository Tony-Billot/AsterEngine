#include "../math/point.h"

typedef struct Square {
    Point p1;
    Point p2;
} Square;

void drawSquare(struct Framebuffer* fb, Square* s, struct Color color);