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

bool detectCycle(Node *head)
{
	Node* fst = head,*slw = head;
    if(fst == NULL || fst->next == NULL)
        return false;
    do
    {
        fst = fst->next->next;
        slw = slw->next;
    }while(fst && fst->next && fst != slw);
    return (fst == slw);
}