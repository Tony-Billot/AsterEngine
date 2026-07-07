#include "../math/point.h"

typedef struct Circle {
    Point center; // Center of the circle
    int radius; // Radius of the circle
} Circle;

void drawCircle(struct Framebuffer* fb, Circle* c, struct Color color);
void drawCircleEx(struct Framebuffer* fb, Circle* c, struct Color color, int isFilled);
static void drawHorizontalLine(struct Framebuffer* fb, int x1, int x2, int y, struct Color color);