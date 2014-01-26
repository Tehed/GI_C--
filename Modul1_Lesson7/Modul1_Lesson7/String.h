#ifndef STRING_H
#define STRING_H

class String
{
public:
    String();
    String(const char* rhs);
    String(const String& rhs);                  // copy constructor
    ~String();                                  // destructor

    String& operator=(const String& rhs);       // assignment operator

    char& operator[](int index);                // bracket operator

private:
    char* mData;
};

#endif