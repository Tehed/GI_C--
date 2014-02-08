//#include <iostream>
//#include <algorithm>
//#include <ctime>
//#include <vector>
//
//using namespace std;
//
//class Print
//{
//public:
//    Print()
//    {    
//    }
//
//    void operator()(int t)
//    {
//        cout << t << " ";
//    }
//};
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
//
//int main()
//{
//    srand(time(0));
//
//    vector<int> intVec(15);
//
//    // intialize with random values and print
//    Random r(1, 10);
//    generate(intVec.begin(), intVec.end(), r);
//    Print p;
//    for_each(intVec.begin(), intVec.end(), p);
//    cout << endl;
//
//    // count, how many times "5" appears
//    int c = count(intVec.begin(), intVec.end(), 5);
//    cout << "5 appears " << c << " times" << endl;
//
//    // replace 5's with "99"
//    replace(intVec.begin(), intVec.end(), 5, 99);
//    
//    c = count(intVec.begin(), intVec.end(), 5);
//    cout << "5 appears " << c << " times" << endl;
//
//    for_each(intVec.begin(), intVec.end(), p);
//    cout << endl;
//
//    c = count(intVec.begin(), intVec.end(), 99);
//    cout << "99 appears " << c << " times" << endl;
//
//    cin.get();
//}