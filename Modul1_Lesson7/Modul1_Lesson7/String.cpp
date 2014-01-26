#include "String.h"
#include <iostream>

String::String()
{
}

String::String(const char* rhs)
{
    int len = strlen(rhs);

    // allocate enough memory (Dynamic allocation!!!)
    mData = new char[len+1];

    for(int i=0; i<len; ++i)
    {
        mData[i] = rhs[i];
    }

    // Set null-character to "end" the string
    mData[len] = '\0';
}

String::String(const String& rhs)
{
}

String::~String()
{
    delete[] mData;
    mData = 0;
}

String& String::operator=(const String& rhs)
{
    // prevent self assignment; 
    // We define that two strings are equal, if their memory address is equal
    if(this == &rhs)
    {
        return *this;
    }

    int len = strlen(rhs.mData);
    
    // free existing memory
    delete[] mData;

    // allocate new memory
    mData = new char[len + 1];

    // copy characters
    for(int i=0; i<len; i++)
    {
        mData[i] = rhs[i];
    }
    mData[len] = '\0';

    // return a reference to *this object
    return *this;
}

char& String::operator[](int index)
{
    return mData[index];
}