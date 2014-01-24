#include <iostream>
#include <string>

#include <cmath>

using namespace std;

float Area(float radius = 1.0f);    // default param

int main()
{
    float f = Area();

    cout << ceil(5.26f);

    // waiting for console
    cin.get();
    return 0;
}



float Area(float radius)
{
    float PI = 3.14f;
    
    float area = PI * radius * radius;
    return area;
}
