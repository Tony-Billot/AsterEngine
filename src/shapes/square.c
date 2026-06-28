#include "../renderer/framebuffer.h"
#include "square.h"

void drawSquare(struct Framebuffer* fb, Square* s, struct Color color) {
    for(int x = s->p1.x; x <= s->p2.x; x++) {
        for(int y = s->p1.y; y <= s->p2.y; y++) {
            putPixel(fb, (Point){x, y}, color);
        }
    }
}