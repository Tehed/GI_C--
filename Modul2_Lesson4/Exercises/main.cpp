#include <iostream>
#include <algorithm>
#include <string>

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

void testLinkedList() 
{
    LinkedList<int> ll;

    cout << "ll is empty? " << ll.isEmpty() << endl;

    ll.insertLast(1);
    ll.insertLast(2);
    ll.insertLast(3);
    ll.insertLast(4);
    ll.insertLast(5);

    ll.insertFirst(0);

    cout << "first element: " << ll.getFirst()->value << endl;

    LinkedNode<int>* current = ll.getFirst();

    int counter = 0;
    while(current != 0)
    {
        //cout << "current: " << counter << ": <- " << current->prev << " - " << current->value << " - " << current->next << " -> " << endl;
        cout << current->value << ", ";
        current = current->next;
    }
}

void testStack()
{
    Stack<string> stack;
    
    cout << "stack is empty? " << stack.isEmpty() << endl;

    stack.push("a");
    stack.push("b");
    stack.push("c");
    stack.push("d");

    while(!stack.isEmpty())
    {
        cout << "elem: " << stack.getTopItem() << endl;
        stack.pop();
    }
}


void testQueue()
{
    Queue<string> queue;

    cout << "queue is empty? " << queue.isEmpty() << endl;

    queue.push("a");
    queue.push("b");
    queue.push("c");
    queue.push("d");

    while(!queue.isEmpty())
    {
        cout << "elem: " << queue.getFirst() << endl;
        queue.pop();
    }
}

int main()
{
    //testLinkedList();

    //testStack();

    testQueue();

    cin.get();
}