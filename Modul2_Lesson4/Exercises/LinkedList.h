
template<typename T>
class LinkedNode
{
public:
    T value;
    LinkedNode* prev;
    LinkedNode* next;
};

template<typename T> 
class LinkedList 
{ 
public: 
    LinkedList(); 
    ~LinkedList();  
    LinkedList(const LinkedList& rhs); 
    LinkedList& operator=(const LinkedList& rhs); 

    bool isEmpty(); 
    LinkedNode<T>* getFirst(); 
    LinkedNode<T>* getLast(); 
    void insertFirst(T data); 
    void insertLast(T data); 
    void insertAfter(T tKey, T tData); 
    void removeFirst(); 
    void removeLast(); 
    void remove(T removalCandidate); 
    void destroy(); 

private: 
    LinkedNode<T>* mFirst; 
    LinkedNode<T>* mLast; 
};

template<typename T>
LinkedList<T>::LinkedList()
{
    mFirst = 0;
    mLast = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    destroy();
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
    destroy();
    *this = rhs;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
    if(*this = rhs) 
    {
        return *this;
    }

    // delete everything
    destroy();

    mFirst = rhs.getFirst()

        LinkedNode* currentLHS = mFirst;
    LinkedNode* currentRHS = rhs.getFirst();

    while(currentRHS != 0)
    {
        currentLHS->value = currentRHS->value;
        currentLHS->prev = currentRHS->prev;
        currentLHS->next = currentRHS->next;

        current = current->next;
    }

    mLast = currentLHS;

    return *this;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
    //return mFirst->next == 0;
    return mFirst == 0;
}

template<typename T>
LinkedNode<T>* LinkedList<T>::getFirst()
{
    return mFirst;
}

template<typename T>
LinkedNode<T>* LinkedList<T>::getLast()
{
    return mLast;
}

template<typename T>
void LinkedList<T>::insertFirst(T data)
{
    if(isEmpty())
    {
        // no first element yet => this becomes the first element
        mFirst = new LinkedNode<T>();
        mFirst->prev = 0;
        mFirst->value = data;
        mFirst->next = mLast;
        return;
    }

     // create new node
    LinkedNode<T>* newNode = new LinkedNode<T>();
    newNode->value = data;
    newNode->prev = 0;
    newNode->next = mFirst;

    // set pointer of former prev node
    mFirst->prev = newNode;

    // set new node as first
    mFirst = newNode;

    if(mLast == 0)
    {
        mLast = mFirst->next;
    }
}

template<typename T>
void LinkedList<T>::insertLast(T data)
{
    if(isEmpty())
    {
        // no first element yet => this becomes the first element
        mFirst = new LinkedNode<T>();
        mFirst->prev = 0;
        mFirst->value = data;
        mFirst->next = mLast;
        return;
    }

    if(mLast == 0)
    {
        // first node set, but no last node yet

        // set last node to new node
        mLast = new LinkedNode<T>();
        mLast->value = data;
        mLast->prev = mFirst;
        mLast->next = 0;

        // set pointer of first node
        mFirst->next = mLast;

        return;
    }

    // create new node
    LinkedNode<T>* newNode = new LinkedNode<T>();
    newNode->value = data;
    newNode->prev = mLast;
    newNode->next = 0;

    // set pointer of former last node
    mLast->next = newNode;

    // set new node as last    
    mLast = newNode;
}

template<typename T>
void LinkedList<T>::insertAfter(T tKey, T tData)
{
}

template<typename T>
void LinkedList<T>::removeFirst()
{
    if(!isEmpty())
    {
        if(mLast != 0 && mLast->prev == 0)
        {
            // last node reached
            destroy();
            return;
        }

        LinkedNode<T>* oldFirst = mFirst;
        mFirst->next->prev = 0;
        mFirst = mFirst->next;

        delete oldFirst;
    }

}


template<typename T>
void LinkedList<T>::removeLast()
{
    if(!isEmpty())
    {
        if(mFirst->next == 0)
        {
            // last element reached
            destroy();
            return;
        }

        // get previous node
        LinkedNode<T>* oldLast = mLast;

        // set pointers
        mLast->prev->next = 0;
        mLast = mLast->prev;

        // delete the old last node
        delete oldLast;
    }
}


template<typename T>
void LinkedList<T>::remove(T removalCandidate)
{
}

template<typename T>
void LinkedList<T>::destroy() 
{ 
    // Is there at least one node in the list?
    if(mFirst != 0) 
    { 
        // Get a pointer to the first node.
        LinkedNode<T>* current = mFirst; 
        // Loop until the end of the list.
        while(current != 0) 
        { 
            // Save the current node. 
            LinkedNode<T>* oldNode = current; 

            // Move to the next node. 
            current = current->next; 

            // Delete the old node. 
            delete oldNode; 
            oldNode = 0; 
        } 
    } 

    mFirst = 0;
}