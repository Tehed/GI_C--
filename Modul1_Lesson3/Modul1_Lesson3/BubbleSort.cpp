//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void BubbleSort(int data[], int n);
//void printData(int data[]);
//
//int main()
//{
//    /*int data[10];
//
//    cout << "give 10 random numbers: " << endl;
//    for(int i=0; i<10; i++)
//    {
//        cout << i << ": "; 
//        cin >> data[i];
//    }*/
//
//    int data[] = {5, -3, 2, 1, 7, -9, 4, -5, 6, -12};
//
//    BubbleSort(data, 10);
//
//    cout << endl << "Sorted List: " << endl;
//    printData(data);
//
//
//    string t = ""; 
//    cin >> t;
//}
//
//static int runCounter = 0;
//
//void BubbleSort(int data[], int n)
//{
//    int subArrayEnd = n;
//
//    while(subArrayEnd > 0)
//    {
//        int nextEnd = 0;
//        for(int i=0; i<subArrayEnd-1; i++) 
//        {
//            if(data[i] > data[i+1])
//            {
//                int temp = data[i];
//                data[i] = data[i+1];
//                data[i+1] = temp;
//
//                nextEnd = i;
//            }
//        }
//
//        subArrayEnd--;
//    }
//}
//
//
//
//void printData(int data[])
//{
//    for(int i=0; i<10; i++)
//    {
//        cout << data[i];
//        if(i<9)
//        {
//            cout << ", "; 
//        }
//        cout << endl;
//    }
//}