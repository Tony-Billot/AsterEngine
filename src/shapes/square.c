#include "../renderer/framebuffer.h"
#include "square.h"

void drawSquare(struct Framebuffer* fb, Square* s, struct Color color) {
    for(int x = s->x1; x <= s->x2; x++) {
        for(int y = s->y1; y <= s->y2; y++) {
            putPixel(fb, x, y, color);
        }
    }
}