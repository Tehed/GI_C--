//#include <iostream>
//#include <string>
//#include <cmath>
//
//using namespace std;
//
//#define PI 3.14159265
//
//float MyArcTangent(float y, float x);
//
//int main()
//{
//    float x = -6.0f;
//    float y = -4.0f;
//
//    float arcTan = MyArcTangent(y, x);
//
//    cout << "arcTan(" << y << ", " << x << "): " << arcTan << endl;
//    cout << "atanf2(" << y << ", " << x << "): " << atan2f(y, x) * 180.0f / PI << endl;
//
//    cin.get();
//}
//
//
///**
//* returns arctan as angle
//*/
//float MyArcTangent(float y, float x) 
//{
//    float angle = atanf(y/x) * 180.0f / PI;
//
//    cout << "atanf: " << angle << endl;
//
//    if((x < 0 && y > 0) || (x < 0 && y < 0))
//    {
//        // point in quadrant 2 or 3
//        angle += 180.0f;
//    }
//
//    return angle ;
//}