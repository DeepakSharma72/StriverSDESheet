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
LinkedListNode<int>* reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL,*cur = head,*nxt;
    while(cur)
    {
        nxt  = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL)
        return true;
    
    LinkedListNode<int>* slw = head,*fst = head->next->next;
    while(fst && fst->next)
    {
        fst = fst->next->next;
        slw = slw->next;
    }
    LinkedListNode<int>* head2 = NULL;
    head2 = reverse(slw->next);   
    slw->next = NULL;
    while(head && head2)
    {
        if(head->data != head2->data)
            return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;
}