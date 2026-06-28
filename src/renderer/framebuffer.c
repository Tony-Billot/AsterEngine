#include <windows.h>
#include <stdlib.h>

struct Framebuffer
{
    int width;
    int height;
    unsigned char* pixels;
};

struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

// Function to create a framebuffer with specified width and height
struct Framebuffer createFrameBuffer(int width, int height)
{
    struct Framebuffer fb;
    fb.width = width;
    fb.height = height;
    fb.pixels = (unsigned char*)malloc(width * height * 4); // Assuming 4 bytes per pixel (RGBA)
    return fb; 
}

// Function to set a pixel in the framebuffer
void putPixel(struct Framebuffer* fb, int x, int y, struct Color color)
{
    if(x < 0 || x >= fb->width || y < 0 || y >= fb->height)
    {
        printf("Error: Pixel coordinates (%d, %d) are out of bounds for framebuffer of size (%d, %d)\n", x, y, fb->width, fb->height);
        return;
    }
    int index = (y * fb->width + x) * 4;
    fb->pixels[index] = color.r;
    fb->pixels[index + 1] = color.g;
    fb->pixels[index + 2] = color.b;
    fb->pixels[index + 3] = color.a;
}


void displayFramebuffer(struct Framebuffer* fb, HWND hwnd) // HWND = screen identifier
{
    // 1. Get the device context of the window
    HDC hdc = GetDC(hwnd); // hdc = handle to device context

    // 2. Describe the bitmap
    BITMAPINFO bmi = {0};

    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = fb->width;
    bmi.bmiHeader.biHeight = -fb->height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32; // 4 bytes per pixel
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biSizeImage = 0;

    // 3. Draw the bitmap to the window
    StretchDIBits(hdc, 0, 0, fb->width, fb->height, 0, 0, fb->width, fb->height, fb->pixels, &bmi, DIB_RGB_COLORS, SRCCOPY);

    // 4. Release the device context
    ReleaseDC(hwnd, hdc);
}

void clearFramebuffer(struct Framebuffer* fb, struct Color color)
{
    for(int y = 0; y < fb->height; y++)
    {
        for(int x = 0; x < fb->width; x++)
        {
            putPixel(fb, x, y, color);
        }
    }
}