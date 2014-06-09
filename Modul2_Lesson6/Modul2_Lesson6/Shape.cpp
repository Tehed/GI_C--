#include "Shape.h"

Shape::Shape(const POINT u, const POINT v, const LOGPEN& lp, const LOGBRUSH& lb)
{
    mPt0.x = u.x;
    mPt0.y = u.y;
    mPt1.x = v.x; 
    mPt1.y = v.y;
    mhPen = CreatePenIndirect(&lp);
    mhBrush = CreateBrushIndirect(&lb);

    mhOldPen = 0;
    mhOldBrush = 0;
}

Shape::~Shape()
{
    DeleteObject(mhPen);
    DeleteObject(mhBrush);
}

void Shape::setStartPt(const POINT& p0)
{
    mPt0 = p0;
}

void Shape::setEndPt(const POINT& p1)
{
    mPt1 = p1;
}

LineShape::LineShape(const POINT u, const POINT v, const LOGPEN& lp, const LOGBRUSH& lb)
    :Shape(u, v, lp, lb)
{ 
    // only calls parent class constructor 
}

void LineShape::draw(HDC hdc)
{
    // save current pen and brush
    mhOldPen = (HPEN) SelectObject(hdc, mhPen);
    mhOldBrush = (HBRUSH) SelectObject(hdc, mhBrush);

    // Draw line
    MoveToEx(hdc, mPt0.x, mPt0.y, 0);
    LineTo(hdc, mPt1.x, mPt1.y);

    // Restore old pen and brush
    SelectObject(hdc, mhOldPen);
    SelectObject(hdc, mhOldBrush);
}

RectShape::RectShape(const POINT u, const POINT v, const LOGPEN& lp, const LOGBRUSH& lb)
    :Shape(u, v, lp, lb)
{ 
    // only calls parent class constructor 
}

void RectShape::draw(HDC hdc)
{
    // save current pen and brush
    mhOldPen = (HPEN) SelectObject(hdc, mhPen);
    mhOldBrush = (HBRUSH) SelectObject(hdc, mhBrush);

    Rectangle(hdc, mPt0.x, mPt0.y, mPt1.x, mPt1.y);

    // Restore old pen and brush
    SelectObject(hdc, mhOldPen);
    SelectObject(hdc, mhOldBrush);
}


EllipseShape::EllipseShape(const POINT u, const POINT v, const LOGPEN& lp, const LOGBRUSH& lb)
    :Shape(u, v, lp, lb)
{ 
    // only calls parent class constructor 
}


void EllipseShape::draw(HDC hdc)
{
    // save current pen and brush
    mhOldPen = (HPEN) SelectObject(hdc, mhPen);
    mhOldBrush = (HBRUSH) SelectObject(hdc, mhBrush);

    Ellipse(hdc, mPt0.x, mPt0.y, mPt1.x, mPt1.y);

    // Restore old pen and brush
    SelectObject(hdc, mhOldPen);
    SelectObject(hdc, mhOldBrush);
}

CubeShape::CubeShape(const POINT u, const POINT v, const LOGPEN& lp, const LOGBRUSH& lb)
    :Shape(u, v, lp, lb)
{ 
    // only calls parent class constructor 
}

void CubeShape::draw(HDC hdc)
{
    // save current pen and brush
    mhOldPen = (HPEN) SelectObject(hdc, mhPen);
    mhOldBrush = (HBRUSH) SelectObject(hdc, mhBrush);

    POINT p0 = mPt0;
    POINT p1;
    POINT p2;
    POINT p3;
    POINT p4;
    POINT p5;
    POINT p6;
    POINT p7 = mPt1;

    p1.y = p0.y; 

    p2.x = p6.x; 

    p4.x = p0.x; 

    p6.y = p7.y; 


    LineShape* l1 = new LineShape(mPt0, mPt1, mhPen, mhBrush);

    // Restore old pen and brush
    SelectObject(hdc, mhOldPen);
    SelectObject(hdc, mhOldBrush);
}
