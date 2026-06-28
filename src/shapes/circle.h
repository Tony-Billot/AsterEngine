typedef struct Circle {
    int x, y; // Center of the circle
    int radius; // Radius of the circle
} Circle;

void drawCircle(struct Framebuffer* fb, Circle* c, struct Color color);