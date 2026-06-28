#include "../renderer/framebuffer.h"
#include <stdlib.h>
#include <windows.h>

#include "../shapes/line.h"


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
        clearFramebuffer(&fb, (struct Color){0, 0, 0, 255});
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


    // Create a black filled framebuffer for background
    Framebuffer black_background = createFrameBuffer(800, 600);
    clearFramebuffer(&black_background, (struct Color){0, 0, 0, 255});

    Line line = {100, 100, 700, 500};
    drawLine(&black_background, &line, (struct Color){255, 0, 0, 255}); // Draw a red line


    // Loop of the program; stops when no message is received anymore (window is closed)
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        displayFramebuffer(&black_background, hwnd);
    }

    return 0;
}
