#ifndef SHAPE_H
#define SHAPE_H

#include "graphics_engine.h"
#include <string>

class Shape : public Object3D
{
public:
    virtual ~Shape();

    // pure virtual functions => have to be implemented by derived classes
    // => Shape becomes an abstract class
    virtual std::string type()  = 0;
    virtual float area()        = 0;
    virtual float perimeter()   = 0;

    // overriden interface method
    virtual void draw()         = 0;
};

class Circle : public Shape
{ 
public: 
    Circle(float rad); 
    std::string type(); 
    float area(); 
    float perimeter(); 

    // overriden interface method
    virtual void draw();

protected: 
    float mRadius; 
}; 

class Rectangle : public Shape 
{ 
public: 
    Rectangle(float w, float l); 
    std::string type(); 
    float area(); 
    float perimeter(); 

    // overriden interface method
    virtual void draw();

protected: 
    float mWidth; 
    float mLength; 
};
#endif