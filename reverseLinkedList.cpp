#include <bits/stdc++.h>
using namespace std;
 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *prevptr = NULL,*curptr = head,*nxtptr = head;
    while(curptr)
    {
        nxtptr = curptr->next;
        curptr->next = prevptr;
        prevptr = curptr;
        curptr = nxtptr;
    }
    return prevptr;
}