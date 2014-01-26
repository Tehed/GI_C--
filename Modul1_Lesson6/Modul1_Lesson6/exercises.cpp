#include <iostream>
#include <string>

using namespace std;

int foo()
{
    static int x = 0;
    x++;
    return x;
}

int main()
{
    //char str[] = "C++ is fun!";

    //cout << sizeof(str) << endl;

    //int x = strcmp("Hello World", "Hi C++");

    //cout << "X: " << x << endl;

    
    int x = 0;

    for(int i=0; i<5; i++)
    {
        x = foo();
    }

    cout << x << endl;

    cin.get();

}