//#include "test.h"
//#include <iostream>
//#include <string>
//#include <deque>
//
//using namespace std;
//
//int main()
//{
//    std::string s1("Hello, ");
//    std::string s2("World.");
//
//    Point2<float> f1(0.0f, 0.0f);
//    Point2<float> f2(5.0f, 5.0f);
//
//    int i1 = 3;
//    int i2 = -3;
//
//    bool b1 = true;
//    bool b2 = false;
//
//    std::string s3 = Add(s1, s2);
//    //Point2<float> f3 = Add(f1, f2);
//    int i3 = Add(i1, i2);
//    bool b3 = Add(b1, b2);
//
//
//    Pair<int, int> iPair(5, -5);
//    Pair<float, std::string> fsPair(3.14f, "pi");
//    Pair<bool, char> bcPair(true, 'A');
//    Pair<Pair<int, int>, Pair<float, std::string> > ppPair(iPair, fsPair);
//
//    deque<char> cd;
//
//    cd.push_back('X');
//    cd.push_back('F');
//    cd.pop_front();
//    cd.push_front('H');
//    cd.push_back('T');
//    cd.pop_back();
//
//    for (deque<char>::iterator it = cd.begin(); it!=cd.end(); ++it)
//    {
//        cout << ' ' << *it;
//    }
//    cout << endl;
//
//    char front = cd.front();
//    char second = cd[1];
//
//    cd.push_front('G');
//    cd.push_front('Z');
//    cd.pop_back();
//
//
//    for (deque<char>::iterator it = cd.begin(); it!=cd.end(); ++it)
//    {
//        cout << ' ' << *it;
//    }
//
//    cout << endl;
//
//    // A -> D -> B -> C -> E -> F
//    char nodes[10] = {'A', 'B', 'C', 'D', 'E', 'F'};
//    int links[10] =  { 3,   2,   4,   1,   5,  -1};
//
//    nodes[6] = 'G';
//    links[6] = links[2];
//    links[2] = 6;
//
//    int p = 0;
//    while(p != -1)
//    {
//        char x = nodes[p];
//        p = links[p];
//        cout << x << ", ";
//    }
//    cout << endl;
//
//    cin.get();
//}