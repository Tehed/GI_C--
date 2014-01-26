#include <iostream>
#include <fstream>
using namespace std;

struct Data
{
      int a, b;
      float x, y;
};

int main()
{
      ofstream outFile("data.txt", ios_base::binary);

      Data d;
      d.a = 1;
      d.b = 2;   
      d.x = -3.14f;
      d.y = 1.76f;

      if(outFile)
      {
          outFile.write((char*)&d, sizeof(d));
          outFile.close();
      }

      ifstream inFile("data.txt", ios_base::binary);

      if(inFile)
      {
          Data e; 
          inFile.read((char*) &e, sizeof(e));
          inFile.close();

          cout << e.a << ", " << e.b << ", " << e.x << ", " << e.y << endl;
      }

      cin.get();
}