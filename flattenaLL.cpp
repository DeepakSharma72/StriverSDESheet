#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* MergeList(Node* l1,Node* l2)
{   
    Node* newhead = new Node(-1);
    Node* ptr = newhead;
    while(l1 && l2)
    {
        if(l1->data <= l2->data)
        {
            ptr->child = l1;
            ptr = ptr->child;
            l1 = l1->child;
        }
        else
        {
            ptr->child = l2;
            ptr = ptr->child;
            l2 = l2->child;
        }
    }
    if(l1)
    {
         ptr->child = l1;
    }
    if(l2)
    {
         ptr->child = l2;
    }
    newhead->child->next = NULL;
    return newhead->child;
}

Node* flattenLinkedList(Node* head) 
{
    if(head == NULL || head->next == NULL)
        return head;
    head->next = flattenLinkedList(head->next);
    head = MergeList(head,head->next);
    return head;
}
