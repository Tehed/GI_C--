//#include<iostream> 
//using namespace std; 
//
////============================================================== 
//// Desc: Function iterates through each element inthe given 
//// array. 
//// array - pointer to the first element of an integer array. 
//// size - the number of elements in the array. 
////============================================================== 
//void PrintArray(int* array, int size) 
//{ 
//    // If the array is of size zero than call it a nullarray. 
//    if( size == 0 ) 
//    { 
//        cout << "NULL Array" << endl; 
//    } 
//    else
//    { 
//        // size not zero so loop through each element and 
//        // print it. 
//        cout << "{"; 
//        for(int i = 0; i < size; ++i) 
//            cout << array[i] << " "; 
//        cout << "}" << endl; 
//    } 
//} 
//
////============================================================== 
//// Desc: Function returns a new array given the new size. 
//// array - pointer to the first element of an integer array. 
//// oldSize - the number of elements currently in 'array'. 
//// newSize - the number of elements we want in the new array. 
////============================================================== 
//int* ResizeArray(int* array, int oldSize, int newSize) 
//{ 
//    // Create an array with the new size. 
//    int* newArray = new int[newSize]; 
//    // New array is a greater size than old array. 
//    if( newSize >= oldSize ) 
//    { 
//        // Copy old elements to new array. 
//        for(int i = 0; i < oldSize; ++i) 
//            newArray[i] = array[i]; 
//    } 
//    // New array is a lesser size than old array. 
//    else // newSize < oldSize 
//    { 
//        // Copy as many old elements to new array as can fit. 
//        for(int i = 0; i < newSize; ++i) 
//            newArray[i] = array[i]; 
//    } 
//
//    // Delete the old array. 
//    delete[] array; 
//
//    // Return a pointer to the new array. 
//    return newArray; 
//} 
//
//int main() 
//{ 
//    // Our main array pointer and a variable to keep track 
//    // of the array size. 
//    int* array = 0; 
//    int arraySize = 0; 
//    // Boolean variable to let us know when the user wants 
//    // to quit, so that we can terminate the loop. 
//    bool done = false; 
//    while( !done ) 
//    { 
//        // Every loop cycle print the array. 
//        PrintArray(array, arraySize); 
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
//            if( index < 0 || index >= arraySize ) 
//            { 
//                cout << "Bad Index!" << endl; 
//            } 
//            else 
//            { 
//                // Ask the user to input the value the user 
//                // wants to assign to element 'index'. 
//                cout << "[" << index << "] = "; 
//                cin >> value; 
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
//            // Call the resize function. Recall that this 
//            // function returns a pointer to the newly resized 
//            // array. 
//            array = ResizeArray(array, arraySize, newSize); 
//            // Update the array size. 
//            arraySize = newSize; 
//            break; 
//            // Quit... 
//        default: 
//            // Cause the loop to terminate. 
//            done = true; 
//            break; 
//        } 
//    } 
//    delete[] array; 
//    array = 0; 
//} 