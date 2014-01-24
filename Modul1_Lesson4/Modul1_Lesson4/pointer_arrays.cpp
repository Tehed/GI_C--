//#include <iostream>
//#include <string>
//#include <ctime>
//
//using namespace std;
//
//void PrintArray(int array[20])
//{
//    cout << "sizeof(array) : " << sizeof(array) << " bytes" << endl;
//
//    for(int i=0; i<20; i++)
//    {
//        cout << array[i] << " ";
//    }
//    cout << endl;
//}
//
//void GetMousePos(int* outX, int* outY)
//{
//    *outX = rand() % 801;
//    *outY = rand() % 601;
//}
//
//int main()
//{
//    short arrayName[8] = {1, 2, 3, 4, 5, 6, 7, 8};
//
//    // pointer to the first element of the array
//    short* firstPtr = arrayName;
//
//    cout << "arrayName[0] = " << arrayName[0] << endl;
//    cout << "*firstPtr = " << *firstPtr << endl; 
//
//    for(int i=0; i<8; i++)
//    {
//        cout << (firstPtr + i) << ": " << *(firstPtr + i) << endl;
//    }
//
//    cout << endl << endl;
//
//    // 2nd example
//    srand(time(0));
//
//    int randomArray[20];
//    for(int i=0; i<20; i++)
//    {
//        randomArray[i] = rand() & 101;
//    }
//
//    cout << "sizeof(randomArray) : " << sizeof(randomArray) << endl;
//    PrintArray(randomArray);
//
//    cout << endl << endl;
//
//    // 3rd example
//    int x = 0;
//    int y = 0;
//
//    GetMousePos(&x, &y);
//
//    cout << x << " / " << y << endl;
//
//    cout << endl;
//
//    cin.get();
//}