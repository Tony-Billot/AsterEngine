#include "../renderer/framebuffer.h"
#include "circle.h"
#include "../math/point.h"

static void drawHorizontalLine(struct Framebuffer* fb, int x1, int x2, int y, struct Color color) {
    if (x1 > x2) {
        int tmp = x1;
        x1 = x2;
        x2 = tmp;
    }

    for (int x = x1; x <= x2; x++) {
        putPixel(fb, (Point){x, y}, color);
    }
}

void drawCircle(struct Framebuffer* fb, Circle* c, struct Color color)
{
    drawCircleEx(fb, c, color, 1);
}

void drawCircleEx(struct Framebuffer* fb, Circle* c, struct Color color, int isFilled) {
    int x = 0;
    int y = c->radius;
    int d = 1 - c->radius;

    while (x <= y) {
        if (isFilled) {
            drawHorizontalLine(fb, c->center.x - x, c->center.x + x, c->center.y + y, color);
            drawHorizontalLine(fb, c->center.x - x, c->center.x + x, c->center.y - y, color);
            drawHorizontalLine(fb,  c->center.x - y, c->center.x + y, c->center.y + x, color);
            drawHorizontalLine(fb,c->center.x - y, c->center.x + y, c->center.y - x, color);
        } else {
            putPixel(fb, (Point){c->center.x + x, c->center.y + y}, color);
            putPixel(fb, (Point){c->center.x + y, c->center.y + x}, color);
            putPixel(fb, (Point){c->center.x - x, c->center.y + y}, color);
            putPixel(fb, (Point){c->center.x - y, c->center.y + x}, color);
            putPixel(fb, (Point){c->center.x - x, c->center.y - y}, color);
            putPixel(fb, (Point){c->center.x - y, c->center.y - x}, color);
            putPixel(fb, (Point){c->center.x + x, c->center.y - y}, color);
            putPixel(fb, (Point){c->center.x + y, c->center.y - x}, color);
        }

        x++;

        if (d < 0) {
            d += 2 * x + 1;
        } else {
            y--;
            d += 2 * (x - y) + 1;
        }
    }
}