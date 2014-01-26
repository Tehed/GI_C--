//#include <string>
//#include <iostream>
//using namespace std;
//
//string reverseString(string input)
//{
//    int lower = 0;
//    int higher = input.length() - 1;
//
//    while(lower < higher -1)
//    {
//        char lowerChar = input[lower];
//        char higherChar = input[higher];
//
//        input[lower] = higherChar;
//        input[higher] = lowerChar;
//
//        lower++;
//        higher--;
//    }
//
//    return input;
//}
//
//int main()
//{
//    string input = "";
//    cout << "Enter a sentence: ";
//    getline(cin, input);
//
//    if(input == reverseString(input))
//    {
//        cout << "Palindrome!" << endl;
//    }
//    else 
//    {
//        cout << "No Palindrome!" << endl;
//    }
//
//    cin.get();
//    cin.get();
//}