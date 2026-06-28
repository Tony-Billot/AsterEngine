#include "../math/point.h"

typedef struct Line {
    Point p1;
    Point p2;
} Line;

void drawLine(struct Framebuffer* fb, Line* l, struct Color color);