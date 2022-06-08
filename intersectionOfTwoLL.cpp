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
    int i = 0;
    while(head)
    {
        head = head->next;
        i++;
    }
    return i;
}

int findIntersection(Node *firstHead, Node *secondHead)
{
    int L1 = getLength(firstHead);
    int L2 = getLength(secondHead);
    if(L1 > L2)
    {
        int i = 0;
        while(i < (L1-L2))
        {
            i++;
            firstHead = firstHead->next;
        }
    }
    else
    {
        int i = 0;
        while(i < (L2 - L1))
        {
            i++;
            secondHead = secondHead->next;
        }
    }
    while(firstHead && secondHead)
    {
        if(firstHead == secondHead)
        {
            return firstHead->data;
        }
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    return -1;
}