#include <bits/stdc++.h> 
/********************************

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

********************************/
int getLength(Node* head)
{
    int l = 0;
    while(head)
    {
        head = head->next;
        l++;
    }
    return l;
}
Node *rotate(Node *head, int k) {
    int N = getLength(head);
    k = k%N;
    if(k == 0)
        return head;
    
    int len = (N/k-1)*k + (N%k);
    int i = 1;
    Node* ptr = head;
    while(i < len)
    {
        ptr = ptr->next;
        i++;
    }
    Node* nwhead = ptr->next;
    ptr->next = NULL;
    ptr = nwhead;
    while(ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = head;
    return nwhead;
}