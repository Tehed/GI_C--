#include <Windows.h>

#include <iostream>
#include <string>


// global variables
HWND ghMainWnd = 0;
HINSTANCE ghAppInst = 0;

const LPCSTR APP_NAME = "MyWindow";
const int windowWidth = 640;
const int windowHeight = 480;


/*
 * helper method
 * determines the screen resolutions and updates the given references
 */
void getScreenResolution(int& width, int& height)
{
    RECT desktop;

    // get handle on desktop window
    const HWND hWnd = GetDesktopWindow();

    // get desktop rectangle
    GetWindowRect(hWnd, &desktop);

    width = desktop.right - desktop.left;
    height = desktop.bottom - desktop.top;
}

/*
 * window procedure
 */
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
    case WM_KEYDOWN:
        if(wParam == VK_ESCAPE)
        {
            DestroyWindow(ghMainWnd);
            return 0;
        }

    case WM_DESTROY: 	
		PostQuitMessage(0); 
		return 0;	
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

WNDCLASS setupWindow() 
{
    WNDCLASS window; 

    window.cbClsExtra = 0;
    window.cbWndExtra = 0;

    window.style = CS_HREDRAW | CS_VREDRAW;
    window.lpfnWndProc = WndProc;
    window.hInstance = ghAppInst;

    window.lpszMenuName = 0;
    window.lpszClassName = APP_NAME;

    window.hIcon = ::LoadIcon(0, IDI_APPLICATION);
    window.hCursor = ::LoadCursor(ghAppInst, IDC_ARROW);

    LOGBRUSH lb; 
    lb.lbStyle = BS_SOLID;
    lb.lbColor = RGB(255, 255, 255);
    window.hbrBackground = CreateBrushIndirect(&lb);


    return window;
}

/*
 * Main method
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd)
{
    ghAppInst = hInstance;

    // setup
    WNDCLASS wndClass = setupWindow();

    // register
    RegisterClass(&wndClass);

    // create window
    ghMainWnd = ::CreateWindow(wndClass.lpszClassName, wndClass.lpszClassName, WS_OVERLAPPEDWINDOW, 0, 0, windowWidth, windowHeight, 0, 0, ghAppInst, 0);

    if(ghMainWnd == 0) 
    {
        ::MessageBox(0, "Couldn't instantiate window", "ERROR", MB_OK);
        return false;
    }

    // show and update
    ShowWindow(ghMainWnd, SW_SHOW);
    UpdateWindow(ghMainWnd);

    // Message Loop
    MSG msg; 
    ZeroMemory(&msg, sizeof(MSG));

    while(GetMessage(&msg, 0, 0, 0)) 
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}
