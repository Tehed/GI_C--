#include "Table.h"
#include "ArrayTemplate.h"
#include <iostream>

using namespace std;


int main()
{
    Table<int> myTable(5, 10); 

    myTable(1, 1) = 2;

    cout << myTable(1,1) << endl;

    ArrayTemplate<float> tArray(5);
    tArray[0] = 1.1f; 
    tArray[1] = 2.5f;

    cout << tArray[0] << " - " << tArray[1] << endl;

    cin.get();
}