#include "shape.h"
#include <string>
#include <iostream>


Shape::~Shape()
{
    // nothing to do here
}

Circle::Circle(float rad) 
    : mRadius(rad) 
{ } 

std::string Circle::type() 
{ 
    return"Circle"; 
} 

const float PI = 3.14f; 

float Circle::area() 
{ 
    return PI*mRadius*mRadius; 
} 

float Circle::perimeter() 
{ 
    return 2.0f*PI*mRadius; 
} 

void Circle::draw()
{
    std::cout << "drawing a circle..." << std::endl;
}

Rectangle::Rectangle(float w, float l)
    : mWidth(w), mLength(l) 
{} 

std::string Rectangle::type() 
{ 
    return "Rectangle"; 
} 

float Rectangle::area() 
{ 
    return mWidth*mLength; 
}

float Rectangle::perimeter() 
{ 
    return 2.0f*mWidth + 2.0f*mLength; 
}

void Rectangle::draw()
{
    std::cout << "drawing a rectangle..." << std::endl;
}
