#ifndef POINT3_H
#define POINT3_H

struct Point3
{
    Point3();
    Point3(float x, float y, float z);
    
    float mX; 
    float mY; 
    float mZ;
};

Point3::Point3()
{
    mX = mY = mZ = 0.0f;
}

Point3::Point3(float x, float y, float z)
{
    mX = x;
    mY = y;
    mZ = z;
}

#endif