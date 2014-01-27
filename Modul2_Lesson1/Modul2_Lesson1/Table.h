#ifndef TABLE_H
#define TABLE_H

template<typename T>
class Table
{
public:
    Table();
    Table(int m, int n);
    Table(int m, int n, const T& value);
    Table(const Table<T>& rhs);
    ~Table();

    Table<T>&   operator=(const Table& rhs);
    T&          operator()(int i, int j);

    int numRows() const;
    int numCols() const;

    void resize(int m, int n);
    void resize(int m, int n, const T& value);

private:
    void destroy();

    int mNumRows;
    int mNumCols;
    T** mDataMatrix;
};

template<typename T>
Table<T>::Table()
{
    mNumCols = 0;
    mNumRows = 0;
    mDataMatrix = 0;
}

template<typename T>
Table<T>::Table(int m, int n)
{
    mNumRows = m;
    mNumCols = n;
    mDataMatrix = 0;
    resize(m, n, T());
}

template<typename T>
Table<T>::Table(int m, int n, const T& value)
{
    mNumRows = m;
    mNumCols = n;
    mDataMatrix = value;
    resize(m, n, value);
}

template<typename T>
Table<T>::Table(const Table<T>& rhs)
{
    mNumCols = rhs.numCols();
    mNumRows = rhs.numRows();
    *this = rhs;
}

template<typename T>
Table<T>::~Table()
{
    destroy();
}

template<typename T>
Table<T>&  Table<T>::operator=(const Table& rhs)
{
    if(this == &rhs)
    {
        // self assignment
        return *this;
    }

    resize(rhs.mNumRows, rhs.mNumCols);

    // copy over entries
    for(int i=0; i<mNumRows; ++i)
    {
        for(int j=0; j<mNumCols; ++j)
        {
            mDataMatrix[i][j] = rhs.mDataMatrix[i][j];
        }
    }

    return *this;
}

template<typename T>
T& Table<T>::operator()(int i, int j)
{
    return mDataMatrix[i][j]; 
}

template<typename T>
int Table<T>::numRows() const
{
    return mNumRows;
}

template<typename T>
int Table<T>::numCols() const
{
    return mNumCols;
}

template<typename T>
void Table<T>::resize(int m, int n)
{
    resize(m, n, T());
}

/*
 * resizes table and initializes the fields with a default value
 */
template<typename T>
void Table<T>::resize(int m, int n, const T& value)
{
    // destroy previous data => we lose data when resizing
    destroy();

    // save dimensions
    mNumRows = m;
    mNumCols = n;

    // Allocate a row (array) of pointers;
    mDataMatrix = new T*[mNumRows];

    // loop through rows and allocate column arrays
    for(int i=0; i<mNumRows; ++i)
    {
        mDataMatrix[i] = new T[mNumCols];

        // copy each element into the newly sized table
        for(int j = 0; j < mNumCols; ++j)
        {
            mDataMatrix[i][j] = value;
        }
    }
}

template<typename T>
void Table<T>::destroy()
{
    // Does the matrix exist? 
    if( mDataMatrix ) 
    { 
        // Iterate over each row i.
        for(int i = 0; i < mNumRows; ++i) 
        { 
            // Does the ith column array exist? 
            if(mDataMatrix[i] ) 
            { 
                // Yes, delete it. 
                delete[]mDataMatrix[i]; 
                mDataMatrix[i] = 0; 
            } 
        } 
        // Now delete the row-array. 
        delete[] mDataMatrix; 
        mDataMatrix = 0; 
    } 

    // Table was destroyed, so dimensions are zero.
    mNumRows = 0;   
    mNumCols = 0; 
}

#endif