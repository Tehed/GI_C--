// Vector3.h

#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>

class Vector3
{
	friend std::istream& operator>>(std::istream& is, Vector3& v);
	friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
public:

	Vector3();
	Vector3(float coords[3]);
	Vector3(float x, float y, float z);

	bool operator==(const Vector3& rhs);
	bool operator!=(const Vector3& rhs);

	Vector3 operator+(const Vector3& rhs);
	Vector3 operator-(const Vector3& rhs);
	Vector3 operator*(float scalar);
	float   operator*(const Vector3& rhs);

	float length();
	void normalize();
	
	operator float*();
 
	void print();
	void input();

	float mX;
	float mY;
	float mZ;
};

std::istream& operator>>(std::istream& is, Vector3& v);
std::ostream& operator<<(std::ostream& os, const Vector3& v);

#endif // VECTOR3_H