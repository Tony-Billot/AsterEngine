#include "../renderer/framebuffer.h"
#include "circle.h"
#include "../math/point.h"

void drawCircle(struct Framebuffer* fb, Circle* c, struct Color color) {
    int x = 0;
    int y = c->radius;
    int d = 1 - c->radius;

    while(x <= y) {
        putPixel(fb, (Point){c->center.x + x, c->center.y + y}, color);
        putPixel(fb, (Point){c->center.x + y, c->center.y + x}, color);
        putPixel(fb, (Point){c->center.x - x, c->center.y + y}, color);
        putPixel(fb, (Point){c->center.x - y, c->center.y + x}, color);
        putPixel(fb, (Point){c->center.x - x, c->center.y - y}, color);
        putPixel(fb, (Point){c->center.x - y, c->center.y - x}, color);
        putPixel(fb, (Point){c->center.x + x, c->center.y - y}, color);
        putPixel(fb, (Point){c->center.x + y, c->center.y - x}, color);

        x++;

        if(d < 0) {
            d += 2 * x + 1;
        } else {
            y--;
            d += 2 * (x - y) + 1;
        }
    }
}