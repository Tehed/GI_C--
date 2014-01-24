#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

/*
 * returns two random numbers in the range [1, 6] using references
 */
void diceFunction(int& die1, int& die2)
{
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
}

/*
 * returns two random numbers in the range [1, 6] using pointers
 */
void diceFunction(int* die1, int *die2)
{
    *die1 = rand() % 6 + 1;
    *die2 = rand() % 6 + 1;
}

void RandomFill(int* array, int size)
{
    for(int i=0; i<size; i++)
    {
        array[i] = rand() % 101;
    }
}

void RandomFill(vector<int>& vec)
{
    for(int i=0; i<vec.size(); i++)
    {
        vec[i] = rand() % 101;
    }
}

void ArrayFill()
{
    int* array; 
    int size = 0; 
    cout << "array size: ";
    cin >> size;

    array = new int[size];

    RandomFill(array, size);

    cout << endl << "{";
    for(int i=0; i<size; i++)
    {
        cout << array[i] << ", "; 
    }
    cout << "}" << endl;

    delete[] array;
}
void VectorFill()
{
    vector<int> vec; 
    int size = 0;
    cout << "array size: ";
    cin >> size;

    vec.resize(size);
    RandomFill(vec);

    cout << endl << "{";
    for(int i=0; i<size; i++)
    {
        cout << vec[i] << ", "; 
    }
    cout << "}" << endl;

}

int main()
{

    // 4.9.2 Dice Function
    srand(time(0));

    int x = 0;
    int y = 0;

    diceFunction(x, y);

    cout << x << " / " << y << endl;

    diceFunction(&x, &y);

    cout << x << " / " << y << endl;


    // Array Fill
    //ArrayFill();
    //VectorFill();




    string end = "";
    cin >> end;
}