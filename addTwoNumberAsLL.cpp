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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *head = new Node(-1);
    Node* ptr = head;
    int carry = 0;
    while(head1 && head2)
    {
        int val = (head1->data + head2->data + carry);
        head1->data = val%10;
        carry = val/10;
        ptr->next = head1;
        ptr = ptr->next;
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1)
    {
        int val = (head1->data + carry);
        head1->data = val%10;
        carry = val/10;
        ptr->next = head1;
        ptr = ptr->next;
        head1 = head1->next;
    }
    while(head2)
    {
        int val = (head2->data + carry);
        head2->data = val%10;
        carry = val/10;
        ptr->next = head2;
        ptr = ptr->next;
        head2 = head2->next;
    }
    if(carry)
    {
        ptr->next = new Node(carry);
    }
    return head->next;
}