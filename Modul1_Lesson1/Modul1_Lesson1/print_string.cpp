#include <iostream>
#include <string>

// so we don't have to write std::cout etc. 
using namespace std;

int main()
{
	/*std::string firstName = "";
	std::cout << "Enter your name: ";
	std::cin >> firstName;
	std::cout << "Hello, " << firstName << std::endl << std::endl;*/

	char letter = 'A';
	int integer = 0;
	float dec = 0.0f;

	cout << "Enter a letter: ";
	cin >> letter;
	cout << endl; // print empty line

    int x = ((2 + 1) * 4) + (8/(2 * (1 + 1))) - (2 * 5) + 5;

    cout << x; 


     const char str[10] = "abc";         
    cout << sizeof(str) << endl;         
    cout << strlen(str) << endl; 

	// waiting for console
	std::string end = "";
	std::cin >> end;
}