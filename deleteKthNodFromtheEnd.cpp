#include <bits/stdc++.h> 
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
int getLength(LinkedListNode<int> *head)
{
    int l = 0;
    while(head && head->data != -1)
    {
        l++;
        head = head->next;
    }
    return l;
}

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(K == 0)
        return head;
    
    int len = getLength(head);
    len = len - K;
    LinkedListNode<int> *prev = NULL,*cur = head;
    while(len >= 1)
    {
        prev = cur;
        cur = cur->next;
        len--;
    }
    if(prev)
    {
        prev->next = cur->next;
    }
    else
    {
        head = cur->next;
    }
    return head;
}