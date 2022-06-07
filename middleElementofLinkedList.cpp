#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/
int getLength(Node* head)
{
    int len = 1;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *findMiddle(Node *head) {
    int len = getLength(head);
    len = len/2 + (len%2);
    while(len > 1)
    {
        len--;
        head = head->next;
    }
    return head;
}