//#include "point3.h"
//#include <fstream>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    // a cube consists of 8 points
//    Point3 cube[8];
//
//    cube[0] = Point3(-1.0f, -1.0f, -1.0f); 
//    cube[1] = Point3(-1.0f, 1.0f, -1.0f); 
//    cube[2] = Point3( 1.0f, 1.0f, -1.0f); 
//    cube[3] = Point3( 1.0f, -1.0f, -1.0f); 
//    cube[4] = Point3(-1.0f, -1.0f, 1.0f); 
//    cube[5] = Point3(-1.0f, 1.0f, 1.0f); 
//    cube[6] = Point3( 1.0f, 1.0f, 1.0f); 
//    cube[7] = Point3( 1.0f, -1.0f, 1.0f); 
//
//    // save data to bin file
//    ofstream outFile("pointdata.txt", ios_base::binary);
//
//    if(outFile)
//    {
//        outFile.write((char*) cube, sizeof(Point3)*8);
//        outFile.close();
//    }
//
//
//    // load data from bin file
//    Point3 cube2[8]; 
//    cout << "BEFORE LOADING..." << endl; 
//    for(int i = 0; i < 8; ++i) 
//    { 
//        cout << "cube2[" << i << "] = "; 
//        cout << "("; 
//        cout << cube2[i].mX << ", "; 
//        cout << cube2[i].mY << ", "; 
//        cout << cube2[i].mZ << ")" << endl; 
//    } 
//
//    ifstream inFile("pointdata.txt", ios_base::binary);
//
//    if(inFile)
//    {
//        inFile.read((char*) cube2, sizeof(Point3)*8);
//        inFile.close();
//    }
//
//    cout << "\nAFTER LOADING..." << endl; 
//    for(int i = 0; i < 8; ++i) 
//    { 
//        cout << "cube2[" << i << "] = "; 
//        cout << "("; 
//        cout << cube2[i].mX << ", "; 
//        cout << cube2[i].mY << ", "; 
//        cout << cube2[i].mZ << ")" << endl; 
//    } 
//
//
//    cin.get();
//}