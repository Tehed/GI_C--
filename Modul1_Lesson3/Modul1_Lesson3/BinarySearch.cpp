//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int BinSearch(int data[], int numElements, int searchKey);
//
//int main()
//{
//    int numbers[23] = {1, 4, 5, 6, 9, 14, 21, 23, 28, 31, 35, 42, 46, 50,53, 57, 62, 63, 65, 74, 79, 89, 95};
//    
//    cout << "{";
//    for(int i=0; i<23; i++)
//    {
//        cout << numbers[i];
//        if(i<22)
//        {
//            cout << ", ";
//        }
//    }
//    cout << "}" << endl;
//
//    bool running = true;
//    while(running)
//    {
//        cout << "Enter search key (or 'x' to exit): ";
//
//        int inputNumber = 0;
//
//        cin >> inputNumber;
//
//        int index = BinSearch(numbers, 23, inputNumber);
//
//        if (index > -1)
//        {
//            cout << endl << inputNumber << " is at position " << index << endl; 
//        }
//        else 
//        {
//            cout << endl << inputNumber << " could not be found" << endl;
//        }
//    }
//
//    cin.get();
//    return 0;
//}
//
//int BinSearch(int data[], int numElements, int searchKey)
//{
//    int result = -1;
//
//    int lowBound = 0;
//    int highBound = numElements -1;
//
//    while(lowBound < highBound)
//    {
//        int currentIndex = (lowBound + highBound) / 2;
//        int currentNumber = data[currentIndex];
//
//        cout << "low: " << lowBound << endl; 
//        cout << "high: " << highBound << endl;
//        cout << "cIndex: " << currentIndex << endl;
//        cout << "cNumber: " << currentNumber << endl;
//
//        if(currentNumber == searchKey)
//        {
//            result = currentIndex;
//            break;
//        }
//        else if (currentNumber > searchKey)
//        {
//            highBound = currentIndex;
//        }
//        else if (currentNumber < searchKey)
//        {
//            lowBound = currentIndex;
//        }
//
//        if((highBound - lowBound) / 2.0f < 1.0f)
//        {
//            break;
//        }
//    }
//    
//    return result;
//}