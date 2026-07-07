#include <windows.h>
#include "../math/point.h"

// Structure definition of a Framebuffer; his sizes and his pixels data (list of pixels in RGBA format)
typedef struct Framebuffer
{
    int width;
    int height;
    unsigned char* pixels;
} Framebuffer;

typedef struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Color;


// Function declarations for framebuffer operations
struct Framebuffer createFrameBuffer(int width, int height);
void putPixel(struct Framebuffer* fb, Point p, struct Color color);
void displayFramebuffer(struct Framebuffer* fb, HWND hwnd);
void clearFramebuffer(struct Framebuffer* fb, struct Color color);
