#include "../math/point.h"

typedef struct Circle {
    Point center; // Center of the circle
    int radius; // Radius of the circle
} Circle;

void drawCircle(struct Framebuffer* fb, Circle* c, struct Color color);