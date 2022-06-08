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
Node* reverseinKgroup(Node* head,int n,int id,int b[])
{
    if(id == n)
    {
        return head;
    }
    int k = b[id];
    int i = 0;
    Node* temp = head;
    while(i<k && temp)
    {
        i++;
        temp = temp->next;
    }
    Node* prev = NULL;
    if(temp)
    {
        prev = reverseinKgroup(temp,n,id+1,b);
    }
    Node*cur = head,*nxt;
    i = 0;
    while(cur && i < k)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
        i++;
    }
    return prev;
}


Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	return reverseinKgroup(head,n,0,b);
}