#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ifstream inFile("wizdata.txt");

    int lineCount = 0;
    string line = "";
    while(!inFile.eof())
    {
        getline(inFile, line);
        lineCount++;
    }

    cout << "the file had " << lineCount << " lines" << endl;

    cin.get();
}