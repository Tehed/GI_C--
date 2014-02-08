using namespace std;

template<typename T> 
class Queue 
{ 
public: 
    Queue();
    ~Queue();
    T& getFirst(); 
    bool isEmpty(); 
    void push(T newElement); 
    void pop(); 

private:
    LinkedList<T> mList;
};

template<typename T> 
Queue<T>::Queue()
{
}

template<typename T> 
Queue<T>::~Queue()
{
    mList.destroy();
}

template<typename T> 
T& Queue<T>::getFirst()
{
    return mList.getFirst()->value;
}

template<typename T> 
bool Queue<T>::isEmpty()
{
    return mList.isEmpty();
}

template<typename T> 
void Queue<T>::push(T newElement)
{
    mList.insertLast(newElement);
}

template<typename T> 
void Queue<T>::pop()
{
    mList.removeFirst();
}
