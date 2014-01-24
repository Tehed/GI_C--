#include<iostream>
#include<string>

using namespace std;

float Square(float x) 
{ 
    return x * x; 
}

//int main() 
//{ 
//    // Get a pointer to Square. Note address of operator (&) 
//    // is not necessary for function pointers. 
//    float(*squarePtr)(float x) = Square; 
//
//    // Call Square via pointer: 
//    cout << "squarePtr(2.0f) = " << squarePtr(2.0f) <<endl; 
//
//    float varFloat = 3.14;
//
//    float * ptr = &varFloat;
//
//    cout << ptr << endl;
//
//    cin.get();
//}

void foo(int*const p)
{
    *p = 5;
}

float dist(float x0, float y0, float x1, float y1)
{
    float dx2 = (x0-x1)*(x0-x1);
    float dy2 = (y0-y1)*(y0-y1);

    return sqrtf( dx2 + dy2 );
}

void GetInfo(std::string& name, int& age, char& sex)
{
    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Enter your sex (m/f): ";
    std::cin >> sex;
}

//int main()
//{       
//    /*
//    // Get the exponential 
//    constant e
//    */
//    const double e = exp(1.0);
//
//    //int x = cube
//
//    /* y = 5*e + 2 */
//
//    int y = 5.0 * e + 2.0;
//
//    std::cout << "5*e + 2 = " << y << std::endl;
//
//    cin.get();
//}