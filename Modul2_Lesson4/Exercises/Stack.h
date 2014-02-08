#include <iostream>

using namespace std;

template<typename T> 
class Stack 
{ 
public: 
    Stack();
    ~Stack(); 
    T& getTopItem(); 
    bool isEmpty(); 
    void push(T newElement); 
    void pop(); 

private: 
    LinkedList<T> mList;
};

template<typename T> 
Stack<T>::Stack()
{
}

template<typename T> 
Stack<T>::~Stack() 
{
    mList.destroy();
}

template<typename T> 
T& Stack<T>::getTopItem() 
{
    return mList.getLast()->value;
}

template<typename T> 
bool Stack<T>::isEmpty()
{
    return mList.isEmpty();
}

template<typename T> 
void Stack<T>::push(T newElement)
{
    mList.insertLast(newElement);
}

template<typename T> 
void Stack<T>::pop()
{
    if(!mList.isEmpty())
    {
        mList.removeLast();
    }
}