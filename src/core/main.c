#include "../renderer/framebuffer.h"
#include <stdlib.h>
#include <windows.h>

#include "../shapes/line.h"
#include "../shapes/square.h"
#include "../shapes/circle.h"
#include "../pictures/picture.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // Handle quitting the window (PostQuitMessage is called when the window is closed)
    if (msg == WM_DESTROY)
    {
        PostQuitMessage(0);
        return 0;
    }

    if (msg == WM_SIZE)
    {
        int width = LOWORD(lParam);
        int height = HIWORD(lParam);

        Framebuffer fb = createFrameBuffer(width, height);
        clearFramebuffer(&fb, (struct Color){255, 255, 255, 255});
        displayFramebuffer(&fb, hwnd);

        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASS wc = {0};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        "MyWindowClass",
        "My Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL, NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {0};


    // Create a white filled framebuffer for background
    Framebuffer white_background = createFrameBuffer(800, 600);
    clearFramebuffer(&white_background, (struct Color){255, 255, 255, 255});

    Circle circle = {(Point){100, 200}, 100};
    drawCircleEx(&white_background, &circle, (struct Color){255, 0, 0, 255}, 1); // Red circle

    Line line = {(Point){100, 100}, (Point){700, 500}};
    drawLine(&white_background, &line, (struct Color){0, 0, 255, 255}); // Blue line

    Square square = {(Point){200, 200}, (Point){600, 400}};
    drawSquare(&white_background, &square, (struct Color){0, 255, 0, 255}); // Green square

    Picture* picture = loadPicture("assets/image.bmp");
    Point picture_position = {300, 100};
    drawPicture(&white_background, picture, picture_position);

    // Loop of the program; stops when no message is received anymore (window is closed)
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        displayFramebuffer(&white_background, hwnd);
    }

    return 0;
}
