#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Point
{
    int x; 
    int y;
};

int main()
{
    float fArray[5] = {1, 2, 3, 4, 5};
    Point p = {5, 10};
    int x = 10;

    ofstream outfile; 
    outfile.open("data.bin", ios_base::binary);

    if(outfile)
    {
        cout << "sizes:" << endl;
        cout << "sizeof(float)*5: " << sizeof(float)*5 << endl;
        cout << "sizeof(Point): " << sizeof(Point) << endl;
        cout << "sizeof(int): " << sizeof(int) << endl;

        outfile.write((char*) fArray, sizeof(float)*5);
        outfile.write((char*) &p, sizeof(Point));
        outfile.write((char*) &x, sizeof(int));
    }
    outfile.close();

    ifstream infile("data.bin", ios_base::binary);

    if(infile)
    {
        float fArray[5];
        Point p;
        int x; 

        infile.read((char*) fArray, sizeof(float)*5);
        infile.read((char*) &p, sizeof(Point));
        infile.read((char*) &x, sizeof(int));

        cout << "read... p: " << p.x << ", " << p.y << endl;
    }

    infile.close();

    cin.get();
}