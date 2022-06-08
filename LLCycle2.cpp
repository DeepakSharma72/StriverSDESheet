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

Node *firstNode(Node *head)
{
	Node* fst = head,*slw = head;
    if(fst == NULL || fst->next == NULL)
        return NULL;
    do
    {
        fst = fst->next->next;
        slw = slw->next;
    }while(fst && fst->next && fst != slw);
    if(fst == NULL || fst->next == NULL)
        return NULL;
    
    fst = head;
    
    int i = -1;
    while(fst != slw)
    {
        fst = fst->next;
        slw = slw->next;
        i++;
    }
    return fst;
}