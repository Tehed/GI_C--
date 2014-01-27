// FloatArray.h 
#ifndef FLOAT_ARRAY_H 
#define FLOAT_ARRAY_H 

template<typename T>
class ArrayTemplate 
{ 
public: 
    // Create a FloatArray with zero elements. 
    ArrayTemplate(); 

    // Create a FloatArray with 'size' elements. 
    ArrayTemplate(int size); 

    // Create a FloatArray from another FloatArray-- 
    // be sure to prevent memory leaks! 
    ArrayTemplate(const ArrayTemplate<T>& rhs); 

    // Free dynamic memory. 
    ~ArrayTemplate(); 

    // Define how a FloatArray shall be assigned to 
    // another FloatArray--be sure to prevent memory 
    // leaks! 
    ArrayTemplate<T>& operator=(const ArrayTemplate<T>& rhs); 

    // Resize the FloatArray to a new size. 
    void resize(int newSize); 

    // Return the number of elements in the array. 
    int size(); 

    // Overload bracket operator so client can index 
    // into FloatArray objects and access the elements. 
    T& operator[](int i); 

private: 
    T* mData;       // Pointer to array of T (dynamic memory). 
    int mSize;      // The number of elements in the array. 
}; 

template<typename T>
ArrayTemplate<T>::ArrayTemplate()
{
    mData = 0;
    mSize = 0;
}

template<typename T>
ArrayTemplate<T>::ArrayTemplate(int size)
{
    mSize = size;
    mData = new T[size];
}

template<typename T>
ArrayTemplate<T>::ArrayTemplate(const ArrayTemplate<T>& rhs)
{
    mSize = 0;
    mData = 0;
    *this = rhs;
}

template<typename T>
ArrayTemplate<T>::~ArrayTemplate()
{
    mSize = 0;
    delete[] mData;
    mData = 0;
}

template<typename T>
ArrayTemplate<T>&  ArrayTemplate<T>::operator=(const ArrayTemplate& rhs)
{
    if(this == rhs)
    {
        return *this;
    }

    // free memory
    delete[] mData;
    
    // allocate new memory
    mData = new T[rhs.mSize];

    // copy data
    mSize = mSize;
    for(int i=0; i<mSize; ++i)
    {
        mData[i] = rhs.mData[i];
    }

    return *this;
}

template<typename T>
void ArrayTemplate<T>::resize(int newSize)
{
    mSize = newSize;

    // fre memory
    delete[] mData;

    mData = new T[mSize];
}

template<typename T>
T& ArrayTemplate<T>::operator[](int i)
{
    return mData[i];
}

#endif // FLOAT_ARRAY_H