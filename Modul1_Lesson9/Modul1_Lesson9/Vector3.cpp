#include "Vector3.h"
#include <cmath>
#include <iostream>

using namespace std;

Vector3::Vector3()
{
    mX = 0.0f;
    mY = 0.0f; 
    mZ = 0.0f;
}

Vector3::Vector3(float coords[3])
{
    mX = coords[0];
    mY = coords[1];
    mZ = coords[2];
}

Vector3::Vector3(float x, float y, float z)
{
    mX = x;
    mY = y; 
    mZ = z;
}

bool Vector3::operator==(const Vector3& rhs)
{
    return mX == rhs.mX && mY == rhs.mY && mZ == rhs.mZ;
}

bool Vector3::operator!=(const Vector3& rhs)
{
    return mX != rhs.mX || mY != rhs.mY || mZ != rhs.mZ;
}

Vector3 Vector3::operator+(const Vector3& rhs)
{
    Vector3 sum;
    sum.mX = mX + rhs.mX;
    sum.mY = mY + rhs.mY;
    sum.mZ = mZ + rhs.mZ;

    return sum;
}

Vector3 Vector3::operator-(const Vector3& rhs)    
{
    Vector3 dif; 
    dif.mX = mX - rhs.mX;
    dif.mY = mY - rhs.mY;
    dif.mZ = mZ - rhs.mZ;

    return dif;
}

Vector3 Vector3::operator*(float scalar)
{
    Vector3 prod;
    prod.mX = mX * scalar;
    prod.mY = mY * scalar;
    prod.mZ = mZ * scalar;

    return prod;
}

float Vector3::operator*(const Vector3& rhs)
{
    float dotP = mX*rhs.mX + mY*rhs.mY + mZ*rhs.mZ;
    return dotP;
}

float Vector3::length()
{
    return sqrtf(mX*mX + mY*mY + mZ*mZ);
}

void Vector3::normalize()
{
    float len = length();

    mX /= len;
    mY /= len;
    mZ /= len;
}

Vector3::operator float*()
{
    // returns the address of the first component of this vector; mY and mZ follow directly after
    return &mX;
}

void Vector3::print()
{
    cout << "<" << mX << ", " << mY << ", " << mZ << "> \n";
}

void Vector3::input()
{
	cout << "Enter x: ";
	cin >> mX;
	cout << "Enter y: ";
	cin >> mY;
	cout << "Enter z: ";
	cin >> mZ;
}

//Vector3 operator*(float scalar,  Vector3& v)
//{
//    return v * scalar;
//}

std::ostream& operator<<(std::ostream& os, const Vector3& v) 
{
    cout << "<" << v.mX << ", " << v.mY << ", " << v.mZ << "> \n";
    return os;
}


std::istream& operator>>(std::istream& is, Vector3& v) 
{
    cout << "Enter x: "; 
    cin >> v.mX; 
    cout << "Enter y: "; 
    cin >> v.mY; 
    cout << "Enter z: "; 
    cin >> v.mZ; 

    return is;
}