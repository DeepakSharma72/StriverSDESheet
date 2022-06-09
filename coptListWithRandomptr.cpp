#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(head == NULL)
        return NULL;
    
    LinkedListNode<int> *ptr = head;
    while(ptr)
    {
        LinkedListNode<int> *n = new LinkedListNode<int>(ptr->data);
        n->next = ptr->next;
        ptr->next = n;
        ptr = n->next;
    }
    ptr = head;
    while(ptr)
    {
        ptr->next->random =  ptr->random;
        
        ptr = ptr->next->next;
    }
    ptr = head;
    LinkedListNode<int> *nwhead = ptr->next;
    LinkedListNode<int> *temp = ptr->next;
    while(temp->next)
    {
        ptr->next = ptr->next->next;
        temp->next = temp->next->next;
        ptr = ptr->next;  
        temp = temp->next;
    }
    ptr->next = NULL;
    return nwhead;
}
