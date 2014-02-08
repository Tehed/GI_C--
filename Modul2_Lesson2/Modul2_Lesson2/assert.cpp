#include <iostream>
#include <string>
#include <cassert>


using namespace std;

void PrintArray(int array[], int size)
{
    assert(array != 0);
    assert(size >= 1);

    for(int i=0; i<size; ++i)
    {
        cout << array[i] << ", "; 
    }
    cout << endl;
}

int main()
{
    int* array = 0;
    PrintArray(array, 10);

    cin.get();
}