typedef struct Square {
    int x1, y1;
    int x2, y2;
} Square;

void drawSquare(struct Framebuffer* fb, Square* s, struct Color color);