#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <Windows.h>

/**
 * Generic shape class
 */
class Shape
{

public:
    Shape(const POINT u, const POINT v, 
        const LOGPEN& lp, const LOGBRUSH& lb);

    // Destructor
    virtual ~Shape();

    void setStartPt(const POINT& p0);
    void setEndPt(const POINT& p1);

    virtual void draw(HDC hdc) = 0;

protected:
    // start and end point
    POINT mPt0;
    POINT mPt1;

    // handles for Pen (lines) and Brush (fills interior of shape)
    HPEN mhPen;
    HBRUSH mhBrush;

    // handler for previously selected pen and brush
    HPEN mhOldPen;
    HBRUSH mhOldBrush;
};

class LineShape : public Shape
{
public:
    LineShape(const POINT u, const POINT v, 
        const LOGPEN& lp, const LOGBRUSH& lb);

    void draw(HDC hdc);
};

class EllipseShape : public Shape
{
public:
    EllipseShape(const POINT u, const POINT v, 
        const LOGPEN& lp, const LOGBRUSH& lb);

    void draw(HDC hdc);
};

class RectShape : public Shape
{
public:
    RectShape(const POINT u, const POINT v, 
        const LOGPEN& lp, const LOGBRUSH& lb);

    void draw(HDC hdc);
};

class CubeShape : public Shape
{
public:
    CubeShape(const POINT u, const POINT v, 
        const LOGPEN& lp, const LOGBRUSH& lb);

    void draw(HDC hdc);

protected:
    std::vector<LineShape*> edges;

};

#endif