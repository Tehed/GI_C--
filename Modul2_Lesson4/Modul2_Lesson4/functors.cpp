//#include <iostream>
//#include <string>
//#include <vector>
//#include <ctime>
//
//#include <algorithm>
//
//using namespace std;
//
//class Print
//{
//public:
//    Print()
//    {
//        blub = 5;
//    }
//
//    void operator()(int t)
//    {
//        cout << t << " ";
//    }
//
//private:
//    int blub;
//};
//
//
//void print(int t)
//{
//    cout << t << "";
//}
//
//void doSomething(void (*function) (int), int t) 
//{
//    function(t);
//}
//
//
//class Random
//{
//public:
//    Random(int low, int high) : mLow(low), mHigh(high) 
//    {
//    }
//
//    int operator()()
//    {
//        return mLow + rand() % (mHigh - mLow + 1);
//    }
//
//private:
//    int mHigh;
//    int mLow;
//
//};
//
///*
// * Functors are "function objects"
// * i.e. an object that acts like a function
// */
//int main()
//{
//    // using functor
//    Print p;
//    p(5);
//
//    cout << endl;
//
//    // using function pointer
//    doSomething(*print, 5);
//
//    cout << endl;
//
//    // using class "Random" and function "generate" as functor
//    srand(time(0));
//
//    vector<int> intVec(10);
//    Random r(2,7);
//    generate(intVec.begin(), intVec.end(), r);      // coming from <algorithm>
//    for_each(intVec.begin(), intVec.end(), p);      // coming from <algorithm>
//
//    cout << endl;
//
//    cin.get();
//}