#include <windows.h>

// Structure definition of a Framebuffer; his sizes and his pixels data (list of pixels in RGBA format)
typedef struct Framebuffer
{
    int width;
    int height;
    unsigned char* pixels;
} Framebuffer;

// Function declarations for framebuffer operations
void displayFramebuffer(struct Framebuffer* fb, HWND hwnd);
struct Framebuffer createFrameBuffer(int width, int height);
void putPixel(struct Framebuffer* fb, int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a);