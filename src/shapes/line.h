typedef struct Line {
    int x1, y1;
    int x2, y2;
} Line;

void drawLine(struct Framebuffer* fb, Line* l, struct Color color);