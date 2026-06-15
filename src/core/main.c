#include "../renderer/framebuffer.h"
#include <stdlib.h>
#include <windows.h>


LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // Handle quitting the window (PostQuitMessage is called when the window is closed)
    if (msg == WM_DESTROY)
    {
        PostQuitMessage(0);
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
    for(int y = 0, x = 0; y < black_background.height; y++)
    {
        for(x = 0; x < black_background.width; x++)
        {
            putPixel(&black_background, x, y, 0, 0, 0, 255);
        }
    }

    // Loop of the program; stops when no message is received anymore (window is closed)
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        displayFramebuffer(&black_background, hwnd);

    }

    return 0;
}
