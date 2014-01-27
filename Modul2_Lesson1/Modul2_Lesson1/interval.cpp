
#include <iostream>
using namespace std;

template<typename T>
struct Interval 
{ 
    Interval(); 
    Interval(T start, T end); 
    T midpoint(); 
    T a; 
    T b; 
}; 

template<typename T>
Interval<T>::Interval() 
{ 
    a = 0.0f;   b = 0.0f;  
} 

template<typename T>
Interval<T>::Interval(T start, T end) 
{ 
    a = start;   b = end;  
} 

template<typename T>
T Interval<T>::midpoint() 
{ 
    // return the midpoint between a and b. 
    return(a + b) * 0.5; 
}

//int main()
//{
//    Interval<float> floatInterval(0.0f, 5.0f); 
//
//    cout << "mid: " << floatInterval.midpoint() << endl;
//
//    cin.get();
//}