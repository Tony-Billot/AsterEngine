#include "../renderer/framebuffer.h"
#include "line.h"


// Bresenham's algorithm to draw a line
void drawLine(struct Framebuffer* fb, Line* l, struct Color color) {
    int dx = l->x2 - l->x1;
    int dy = l->y2 - l->y1;
    int err = 0;
    int y = l->y1;

    for (int x = l->x1; x <= l->x2; x++) {
        putPixel(fb, x, y, color);
        err += dy;
        if (2 * err >= dx) {
            y++;
            err -= dx;
        }
    }
}