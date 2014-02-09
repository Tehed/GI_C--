#include "stdafx.h"
#include "Resource.h"

#include <iostream>
#include <string>

// global handles to the main window and application 
HWND ghMainWnd = 0; 
HINSTANCE ghAppInst = 0; 


void handleButtonDown()
{
    int r = MessageBox(0, "Error Message", "Title", MB_YESNOCANCEL);

    if( r == IDYES )
        MessageBox(0, "IDYES", 0, 0);
    else if( r == IDNO )
        MessageBox(0, "IDNO", 0, 0);
    else if( r == IDCANCEL )
        MessageBox(0, "IDCANCEL", 0, 0);
    else if( r == 0 )
        MessageBox(0, "FAILED", 0, 0);
}

/*
* Defining the window procedure (= special function each window has to handle event messages)
* CALLBACK: 
*      -> will be called by the win32 API when a message from the message loop is dispatched to it
* WPARAM
*      -> 32 bit value; information depending on the message
* LPARAM
*      -> 32 bit-value; information depending on the message
*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
    case WM_LBUTTONDOWN:
        //MessageBox(0, "WM_LBUTTONDOWN message", "Msg", MB_OK);
        handleButtonDown();
        return 0;
        break;

    case WM_KEYDOWN:
        if(wParam == VK_ESCAPE) 
        {
            int youSrs = MessageBox(0, "Are you sure?" , "sure?", MB_YESNO);

            if(youSrs == IDYES)
            {
                // will send a WM_DESTROY message
                DestroyWindow(ghMainWnd);
            }
            return 0;
        }
        break;

    case WM_DESTROY:            // coming from clicking the "X"-Button or by calling DestroyWindow(HWND hwnd);
        PostQuitMessage(0);     // adds a WM_QUIT message to the message queue (parameter = exit code)
        return 0;

    }

    return DefWindowProc(hwnd, msg, wParam, lParam);        // passes message on to "default implementation"
}

LRESULT CALLBACK WndProc2(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
    case WM_LBUTTONDOWN:
        MessageBox(0, "cool, bro", "Msg", MB_OK);
        return 0;
        break;

    case WM_KEYDOWN:
        if(wParam == VK_ESCAPE) 
        {
            int youSrs = MessageBox(0, "Are you sure?" , "sure?", MB_YESNO);

            if(youSrs == IDYES)
            {
                // will send a WM_DESTROY message
                DestroyWindow(hwnd);
            }
            return 0;
        }
        break;

    case WM_DESTROY:            // coming from clicking the "X"-Button or by calling DestroyWindow(HWND hwnd);
        DestroyWindow(hwnd);
        return 0;

    }

    return DefWindowProc(hwnd, msg, wParam, lParam);        // passes message on to "default implementation"
}

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

WNDCLASS setupWindow1()
{
    WNDCLASS window;
    window.style = CS_HREDRAW | CS_VREDRAW;
    window.lpfnWndProc = WndProc;                                   // pointer to window procedure
    window.cbClsExtra = 0;                                          // not needed here
    window.cbWndExtra = 0;                                          // not needed here
    window.hInstance = ghAppInst;
    //window.hIcon = ::LoadIcon(0, IDI_APPLICATION);
    window.hIcon = ::LoadIcon(ghAppInst, MAKEINTRESOURCE(IDI_MODUL2_LESSON5));
    window.hCursor = ::LoadCursor(0, IDC_ARROW);
    LOGBRUSH lb; 
    lb.lbStyle = BS_SOLID;
    lb.lbColor = RGB(5,5,255);
    //window.hbrBackground = (HBRUSH) GetStockObject(CreateBrushIndirect(&lb));
    window.hbrBackground = CreateBrushIndirect(&lb);
    window.lpszMenuName = 0;                                        // we will create menus of our own
    window.lpszClassName = "MyWndClassName1";                        // string identifier

    return window;
}

WNDCLASS setupWindow2()
{
    WNDCLASS window;
    window.style = CS_HREDRAW | CS_VREDRAW;
    window.lpfnWndProc = WndProc2;                                  // pointer to window procedure
    window.cbClsExtra = 0;                                          // not needed here
    window.cbWndExtra = 0;                                          // not needed here
    window.hInstance = ghAppInst;
    window.hIcon = ::LoadIcon(ghAppInst, MAKEINTRESOURCE(IDI_MODUL2_LESSON5));
    window.hCursor = ::LoadCursor(0, IDC_ARROW);
    LOGBRUSH lb; 
    lb.lbStyle = BS_SOLID;
    lb.lbColor = RGB(100,0, 0);
    window.hbrBackground = CreateBrushIndirect(&lb);
    window.lpszMenuName = 0;                                        // we will create menus of our own
    window.lpszClassName = "MyWndClassName2";                        // string identifier

    return window;
}


/*
* Main function
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd)
{
    // Save handle to application instance. 
    ghAppInst = hInstance; 

    // get screen size
    int windowWidth = 640;
    int windowHeight = 480;
    int screenWidth = 0;
    int screenHeight = 0;
    getScreenResolution(screenWidth, screenHeight);

    // debug output
    char msgBuff[255]; 
    sprintf_s(msgBuff, 255, "screen: %d x %d \n", screenWidth, screenHeight );
    OutputDebugString(msgBuff);

    // setup window properties with WNDCLASS structure
    WNDCLASS wnd1 = setupWindow1();
    WNDCLASS wnd2 = setupWindow2();

    // register window with Windows
    RegisterClass(&wnd1);                                         // RegisterClass takes a pointer as parameter
    RegisterClass(&wnd2);

    // create the window
    ghMainWnd = ::CreateWindow(wnd1.lpszClassName, "MyWindow", WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,
        (screenWidth/2), 0, windowWidth, windowHeight, 0, 0, ghAppInst, 0);

    HWND hWindow2 = ::CreateWindow(wnd2.lpszClassName, "MyWindow2", WS_OVERLAPPEDWINDOW, 
        0, 0, windowWidth, windowHeight, 0, 0, ghAppInst, 0);

    if(ghMainWnd == 0 || hWindow2 == 0)
    {
        ::MessageBox(0, "Couldn't instantiate window!", "ERROR", MB_OK);
        return false;
    }

    // show and update the window
    ShowWindow(ghMainWnd, SW_SHOW);
    UpdateWindow(ghMainWnd);

    ShowWindow(hWindow2, SW_SHOW);
    UpdateWindow(hWindow2);

    // Message Loop (i.e. waiting for messages)
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));                                  // clears out all bits of a variable to zero

    while(GetMessage(&msg, 0, 0, 0))
    {
        TranslateMessage(&msg);                                     // Keycode to Character-Code translateions
        DispatchMessage(&msg);                                      // forwards message to window procedure (callback)
    }


    // return exit code back to OS
    return (int)msg.wParam;
}
