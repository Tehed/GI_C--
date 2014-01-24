#include <string>
#include <iostream>

using namespace std;

int main() 
{
   /* int intArray[8];
    
    for(int i=0; i<8; i++)
    {
        intArray[i] = i;
    }

    int sum = 0; 
    for(int i=0; i<8; i++)
    {
        cout << intArray[i] << endl;
        sum += intArray[i];
    }

    cout << "Result: " << sum << endl;*/

    /*bool b =  (!(3 == 5) || (5 <= 7)) && ((A && B) || C)
        = (!false || true) && ((A && B) || C)
        = true && ((A && B) || C);*/

        std::string str[2][2] = { {"s11", "s12"}, {"s21", "s22"} };

        bool b =  (3 != 5) && !(true || false || true);

        cout << b << endl;

        for(float x = 1.5f; x < 55.0f; x*=2.0f)
            cout << x << endl;




    // debug console wait
    string t = "";
    cin >> t;
}
