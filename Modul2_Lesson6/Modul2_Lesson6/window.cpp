#include <Windows.h>

#include <iostream>
#include <string>
#include <vector>
#include "stdio.h"

#include "Shape.h"
#include "resource.h"


/**
 * stores a string and the position where to paint it
 */
struct TextObj
{
    std::string s;
    POINT p;
};

struct Line
{
    POINT p0;
    POINT p1;
};

// some color constants
const COLORREF BLACK = RGB(0, 0, 0); 
const COLORREF WHITE = RGB(255, 255, 255);
const COLORREF RED = RGB(255, 0, 0); 
const COLORREF GREEN = RGB(0, 255, 0); 
const COLORREF BLUE = RGB(0, 0, 255);


// global variables
HWND ghMainWnd = 0;
HINSTANCE ghAppInst = 0;

const LPCSTR APP_NAME = "MyWindow";
const int windowWidth = 640;
const int windowHeight = 480;

bool gMouseDown = false;

//std::vector<TextObj> gTextObjs;
//std::vector<Line> gLines;
//Line gLine; // temporary current line
//std::vector<RECT> gRects;
//RECT gRect; //temporary current RECT

std::vector<Shape*> gShapes;
Shape* gShape = 0; // temporary current Shape

// currently selected primitive (i.e. Menu Item)
int gCurrPrimSel = ID_PRIMITIVE_LINE;;   
int gCurrPenColSel = ID_PENCOLOR_BLACK; 
int gCurrBrushColSel = ID_BRUSHCOLOR_BLACK; 
int gCurrPenStyleSel = ID_PENSTYLE_SOLID; 
int gCurrBrushStyleSel = ID_BRUSHSTYLE_SOLID;

// currently selected pen and bruch
LOGPEN gLogPen;
LOGBRUSH gLogBrush;

// Resources
HBITMAP gHBitMap;
HMENU gHMenu;



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
    // Objects for painting
    HDC hdc = 0;
    PAINTSTRUCT ps;

    // Local POINT variables for some commands
    POINT p0; 
    POINT p1; 

    //TextObj to;

    switch(msg)
    {
    case WM_CREATE:

        CheckMenuItem(gHMenu, ID_PRIMITIVE_LINE, MF_CHECKED);
        CheckMenuItem(gHMenu, ID_PENCOLOR_BLACK, MF_CHECKED);
        CheckMenuItem(gHMenu, ID_BRUSHCOLOR_BLACK, MF_CHECKED);
        CheckMenuItem(gHMenu, ID_PENSTYLE_SOLID, MF_CHECKED);
        CheckMenuItem(gHMenu, ID_BRUSHSTYLE_SOLID, MF_CHECKED);

        return 0;

    case WM_KEYDOWN:
        if(wParam == VK_ESCAPE)
        {
            DestroyWindow(ghMainWnd);
            return 0;
        }

    case WM_DESTROY: 	
		PostQuitMessage(0); 
		return 0;	

    case WM_COMMAND:
        // user selected a menu item

        CheckMenuItem(gHMenu, LOWORD(wParam), MF_CHECKED);

        switch(LOWORD(wParam))
        {
        case ID_FILE_EXIT:
            DestroyWindow(ghMainWnd);
            return 0;

        case ID_PRIMITIVE_LINE:
            CheckMenuItem(gHMenu, gCurrPrimSel, MF_UNCHECKED);
            gCurrPrimSel = ID_PRIMITIVE_LINE;
            return 0;

        case ID_PRIMITIVE_RECTANGLE:
            CheckMenuItem(gHMenu, gCurrPrimSel, MF_UNCHECKED);
            gCurrPrimSel = ID_PRIMITIVE_RECTANGLE;
            return 0;

        case ID_PRIMITIVE_ELLIPSE:
            CheckMenuItem(gHMenu, gCurrPrimSel, MF_UNCHECKED);
            gCurrPrimSel = ID_PRIMITIVE_ELLIPSE;
            return 0;

        case ID_PRIMITIVE_CUBE:
            CheckMenuItem(gHMenu, gCurrPrimSel, MF_UNCHECKED);
            gCurrPrimSel = ID_PRIMITIVE_CUBE;
            return 0;

        case  ID_PENCOLOR_BLACK:
            CheckMenuItem(gHMenu, gCurrPenColSel, MF_UNCHECKED);
            gCurrPenColSel = ID_PENCOLOR_BLACK;
            gLogPen.lopnColor = BLACK;
            return 0;

        case  ID_PENCOLOR_WHITE:
            CheckMenuItem(gHMenu, gCurrPenColSel, MF_UNCHECKED);
            gCurrPenColSel = ID_PENCOLOR_WHITE;
            gLogPen.lopnColor = WHITE;
            return 0;

        case  ID_PENCOLOR_RED:
            CheckMenuItem(gHMenu, gCurrPenColSel, MF_UNCHECKED);
            gCurrPenColSel = ID_PENCOLOR_RED;
            gLogPen.lopnColor = RED;
            return 0;

        case  ID_PENCOLOR_GREEN:
            CheckMenuItem(gHMenu, gCurrPenColSel, MF_UNCHECKED);
            gCurrPenColSel = ID_PENCOLOR_GREEN;
            gLogPen.lopnColor = GREEN;
            return 0;

        case  ID_PENCOLOR_BLUE:
            CheckMenuItem(gHMenu, gCurrPenColSel, MF_UNCHECKED);
            gCurrPenColSel = ID_PENCOLOR_BLUE;
            gLogPen.lopnColor = BLUE;
            return 0;

        case  ID_BRUSHCOLOR_BLACK:
            CheckMenuItem(gHMenu, gCurrBrushColSel, MF_UNCHECKED);
            gCurrBrushColSel = ID_BRUSHCOLOR_BLACK;
            gLogBrush.lbColor = BLACK;
            return 0;

        case  ID_BRUSHCOLOR_WHITE:
            CheckMenuItem(gHMenu, gCurrBrushColSel, MF_UNCHECKED);
            gCurrBrushColSel = ID_BRUSHCOLOR_WHITE;
            gLogBrush.lbColor = WHITE;
            return 0;

        case  ID_BRUSHCOLOR_RED:
            CheckMenuItem(gHMenu, gCurrBrushColSel, MF_UNCHECKED);
            gCurrBrushColSel = ID_BRUSHCOLOR_RED;
            gLogBrush.lbColor = RED;
            return 0;

        case  ID_BRUSHCOLOR_GREEN:
            CheckMenuItem(gHMenu, gCurrBrushColSel, MF_UNCHECKED);
            gCurrBrushColSel = ID_BRUSHCOLOR_GREEN;
            gLogBrush.lbColor = GREEN;
            return 0;

        case  ID_BRUSHCOLOR_BLUE:
            CheckMenuItem(gHMenu, gCurrBrushColSel, MF_UNCHECKED);
            gCurrBrushColSel = ID_BRUSHCOLOR_BLUE;
            gLogBrush.lbColor = BLUE;
            return 0;

        case  ID_PENSTYLE_SOLID:
            CheckMenuItem(gHMenu, gCurrPenStyleSel, MF_UNCHECKED);
            gCurrPenStyleSel = ID_PENSTYLE_SOLID;
            gLogPen.lopnStyle = PS_SOLID;
            return 0;

        case  ID_PENSTYLE_DOTTED:
            CheckMenuItem(gHMenu, gCurrPenStyleSel, MF_UNCHECKED);
            gCurrPenStyleSel = ID_PENSTYLE_DOTTED;
            gLogPen.lopnStyle = PS_DOT;
            return 0;

        case  ID_PENSTYLE_DASHED:
            CheckMenuItem(gHMenu, gCurrPenStyleSel, MF_UNCHECKED);
            gCurrPenStyleSel = ID_PENSTYLE_DASHED;
            gLogPen.lopnStyle = PS_DASH;
            return 0;

        case  ID_BRUSHSTYLE_SOLID:
            CheckMenuItem(gHMenu, gCurrBrushStyleSel, MF_UNCHECKED);
            gCurrBrushStyleSel = ID_BRUSHSTYLE_SOLID;
            gLogBrush.lbStyle = BS_SOLID;
            return 0;

        case  ID_BRUSHSTYLE_DIAGONAL:
            CheckMenuItem(gHMenu, gCurrBrushStyleSel, MF_UNCHECKED);
            gCurrBrushStyleSel = ID_BRUSHSTYLE_DIAGONAL;
            gLogBrush.lbStyle = BS_HATCHED;
            gLogBrush.lbHatch = HS_FDIAGONAL;
            return 0;

        case  ID_BRUSHSTYLE_CROSS:
            CheckMenuItem(gHMenu, gCurrBrushStyleSel, MF_UNCHECKED);
            gCurrBrushStyleSel = ID_BRUSHSTYLE_CROSS;
            gLogBrush.lbStyle = BS_HATCHED;
            gLogBrush.lbHatch = HS_CROSS;
            return 0;
        }


    case WM_LBUTTONDOWN:
        //to.s = "Hello World";
        //to.p.x = LOWORD(lParam);
        //to.p.y = HIWORD(lParam);

        //gTextObjs.push_back(to);

        //// forces WM_PAINT; "0" == whole window is redrawn; "false" == window should not be erased before redrawing
        //InvalidateRect(hwnd, 0, false);

        // captures mouse input for this window (i.e. window will receive mouse events even if mouse is moved outside)
        //SetCapture(hwnd);

        //gMouseDown = true;

        //gLine.p0.x = LOWORD(lParam);
        //gLine.p0.y = HIWORD(lParam);

        //gRect.left = LOWORD(lParam);
        //gRect.top = HIWORD(lParam);

        p0.x = LOWORD(lParam);
        p0.y = HIWORD(lParam);

        p1.x = LOWORD(lParam);
        p1.y = HIWORD(lParam);

        gMouseDown = true;

        switch(gCurrPrimSel)
        {
        case ID_PRIMITIVE_LINE:
            gShape = new LineShape(p0, p1, gLogPen, gLogBrush);
            return 0;

        case ID_PRIMITIVE_RECTANGLE:
            gShape = new RectShape(p0, p1, gLogPen, gLogBrush);
            return 0;

        case ID_PRIMITIVE_ELLIPSE:
            gShape = new EllipseShape(p0, p1, gLogPen, gLogBrush);
            return 0;

        case ID_PRIMITIVE_CUBE:
            gShape = new CubeShape(p0, p1, gLogPen, gLogBrush);
            return 0;
        }

        return 0;

    case WM_MOUSEMOVE:

        if(gMouseDown)
        {
            //gLine.p1.x = LOWORD(lParam);
            //gLine.p1.y = HIWORD(lParam);

            //gRect.right = LOWORD(lParam);
            //gRect.bottom = HIWORD(lParam);

            p1.x = LOWORD(lParam);
            p1.y = HIWORD(lParam);

            gShape->setEndPt(p1);
            gShape->draw(hdc);

            InvalidateRect(hwnd, 0, true);
        }

        return 0;

    case WM_LBUTTONUP:
        ReleaseCapture();
        gMouseDown = false;

        //gLine.p1.x = LOWORD(lParam);
        //gLine.p1.y = HIWORD(lParam);
        //gLines.push_back(gLine);

        //gRect.right = LOWORD(lParam);
        //gRect.bottom = HIWORD(lParam);
        //gRects.push_back(gRect);

        p1.x = LOWORD(lParam);
        p1.y = HIWORD(lParam);

        gShape->setEndPt(p1);

        gShapes.push_back(gShape);

        InvalidateRect(hwnd, 0, true);

        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);

        // bitmap rendering
        BITMAP bitmap = {0};
        GetObject(gHBitMap, sizeof(BITMAP), &bitmap);

        // create "system memory device context"
        HDC bmHDC = CreateCompatibleDC(hdc);

        // hook up bitmap to the "system memory device context
        HBITMAP oldBM = (HBITMAP) SelectObject(bmHDC, gHBitMap);

        // Now copy the pixels from the bitmap bmHDC has selected
		// to the pixels from the client area hdc has selected.
		BitBlt(
			hdc,                // Destination DC.
			0,                  // 'left' coordinate of destination rectangle.
			0,                  // 'top' coordinate of destination rectangle.
            bitmap.bmWidth,     // 'right' coordinate of destination rectangle.
			bitmap.bmHeight,    // 'bottom' coordinate of destination rectangle.
			bmHDC,              // Bitmap source DC.
			0,                  // 'left' coordinate of source rectangle.
			0,                  // 'top' coordinate of source rectangle.
			SRCCOPY);           // Copy the source pixels directly to the destination pixels
		
        // select the originally loaded bitmap
        SelectObject(bmHDC, oldBM);

        // delete the system memory device context
        DeleteDC(bmHDC);


        // paint text objects
        //for(int i=0; i<gTextObjs.size(); ++i)
        //{
        //    TextOut(hdc, 
        //        gTextObjs.at(i).p.x,
        //        gTextObjs.at(i).p.y,
        //        gTextObjs.at(i).s.c_str(),
        //        gTextObjs.at(i).s.size());
        //}

        //for(int i=0; i<gRects.size(); ++i)
        //{
        //    //MoveToEx(hdc, gLines[i].p0.x, gLines[i].p0.y, 0);
        //    //LineTo(hdc, gLines[i].p1.x, gLines[i].p1.y);
        //    Rectangle(hdc, gRects[i].left, gRects[i].top, gRects[i].right, gRects[i].bottom);
        //}

        for(int i=0; i<gShapes.size(); ++i)
        {
            gShapes[i]->draw(hdc);
        }

        if(gMouseDown)
        {
            gShape->draw(hdc);
            //MoveToEx(hdc, gLine.p0.x, gLine.p0.y, 0);
            //LineTo(hdc, gLine.p1.x, gLine.p1.y);
            //Rectangle(hdc, gRect.left, gRect.top, gRect.right, gRect.bottom);
            //Ellipse(hdc, gRect.left, gRect.top, gRect.right, gRect.bottom);
        }

        EndPaint(hwnd, &ps);
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

void loadResources()
{
    gHBitMap = LoadBitmap(ghAppInst, MAKEINTRESOURCE(IDB_BITMAP1));
    gHMenu = LoadMenu(ghAppInst, MAKEINTRESOURCE(IDR_MENU1));
}

/*
 * Main method
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd)
{
    ghAppInst = hInstance;

    OutputDebugString("loading resources...");
    loadResources();


    OutputDebugString("starting window...");

    // setup
    WNDCLASS wndClass = setupWindow();

    // register
    RegisterClass(&wndClass);

    // create window
    ghMainWnd = CreateWindow(wndClass.lpszClassName, wndClass.lpszClassName, WS_OVERLAPPEDWINDOW, 200, 200, windowWidth, windowHeight, 0, gHMenu, ghAppInst, 0);

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

