#include "../renderer/framebuffer.h"
#include "line.h"


// Bresenham's algorithm to draw a line
void drawLine(struct Framebuffer* fb, Line* l, struct Color color) {
    int dx = l->p2.x - l->p1.x;
    int dy = l->p2.y - l->p1.y;
    int err = 0;
    int y = l->p1.y;

    for (int x = l->p1.x; x <= l->p2.x; x++) {
        putPixel(fb, (Point){x, y}, color);
        err += dy;
        if (2 * err >= dx) {
            y++;
            err -= dx;
        }
    }
}