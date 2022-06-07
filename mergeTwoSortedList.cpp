#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int> *head  = NULL;
    Node<int> *tail = NULL;
    while(first && second)
    {
        if(first->data <= second->data)
        {
            if(tail == NULL)
            {
                tail = head = first;
            }
            else
            {
                tail->next = first; 
                 tail = tail->next;
            }
            first = first->next;
        }
        else
        {
            if(tail == NULL)
            {
                tail = head = second;
            }
            else
            {
                tail->next = second; 
                 tail = tail->next;
            }
            second = second->next;
        }
    }
    if(tail)
    tail->next = (first == NULL)?second:first;
    else
        head = tail = (first == NULL)?second:first;
    return head;
}
