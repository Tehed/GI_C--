//#include<iostream> 
//#include<vector>
//using namespace std; 
//
////============================================================== 
//// Desc: Function iterates through each element inthe given 
//// array. 
//// array - pointer to the first element of an integer array. 
//// size - the number of elements in the array. 
////============================================================== 
//void PrintArray(vector<int>& v) 
//{ 
//    // If the array is of size zero than call it a nullarray. 
//    if( v.size() == 0 ) 
//    { 
//        cout << "NULL Array" << endl; 
//    } 
//    else
//    { 
//        // size not zero so loop through each element and 
//        // print it. 
//        cout << "{"; 
//        for(int i = 0; i < v.size(); ++i) 
//            cout << v[i] << " "; 
//        cout << "}" << endl; 
//    } 
//} 
//
//
//int main() 
//{ 
//    // Our main vector   
//    vector<int> array;
//
//    // Boolean variable to let us know when the user wants 
//    // to quit, so that we can terminate the loop. 
//    bool done = false; 
//    while( !done ) 
//    { 
//        // Every loop cycle print the array. 
//        PrintArray(array); 
//
//        // Print a menu giving the user a list of options. 
//        cout << 
//            "1) Set Element " 
//            "2) Resize Array " 
//            "3) Quit "; 
//
//        // Input the users selection. 
//        int selection = 1; 
//        cin >> selection; 
//
//        // Some variables that will receive additional input 
//        // depending on the users selection. 
//        int index = -1; 
//        int value = 0; 
//        int newSize = 0; 
//
//        // Find out what menu option the user selected. 
//        switch( selection ) 
//        { 
//            // Case 1: Set Element 
//        case 1: 
//            // Ask for the index of the element the user wants 
//            // to set. 
//            cout << "Index = "; 
//            cin >> index; 
//            // Make sure index is "in array bounds." 
//            if( index < 0 || index >= array.size() ) 
//            { 
//                cout << "Bad Index!" << endl; 
//            } 
//            else 
//            { 
//                // Ask the user to input the value the user 
//                // wants to assign to element 'index'. 
//                cout << "[" << index << "] = "; 
//                cin >> value; 
//
//                // Set the value the user entered to the index 
//                // the user specified. 
//                array[index] = value; 
//            } 
//            break; 
//            // Case 2: Resize Array 
//        case 2: 
//            // Ask the user to enter the size of the new array.
//            cout << "Size = "; 
//            cin >> newSize; 
//            
//            // Call the resize function. 
//            array.resize(newSize);
//
//            break; 
//            // Quit... 
//
//        default: 
//            // Cause the loop to terminate. 
//            done = true; 
//            break; 
//        } 
//    } 
//} 