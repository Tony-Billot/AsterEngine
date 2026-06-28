#include "../renderer/framebuffer.h"
#include "circle.h"

void drawCircle(struct Framebuffer* fb, Circle* c, struct Color color) {
    int x = 0;
    int y = c->radius;
    int d = 1 - c->radius;

    while(x <= y) {
        putPixel(fb, c->x + x, c->y + y, color);
        putPixel(fb, c->x + y, c->y + x, color);
        putPixel(fb, c->x - x, c->y + y, color);
        putPixel(fb, c->x - y, c->y + x, color);
        putPixel(fb, c->x - x, c->y - y, color);
        putPixel(fb, c->x - y, c->y - x, color);
        putPixel(fb, c->x + x, c->y - y, color);
        putPixel(fb, c->x + y, c->y - x, color);

        x++;

        if(d < 0) {
            d += 2 * x + 1;
        } else {
            y--;
            d += 2 * (x - y) + 1;
        }
    }
}