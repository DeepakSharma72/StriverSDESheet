struct Node{
    int val;
    Node* next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class Queue {
    Node* head,*tail;
public:
    Queue() {
        head = NULL;
        tail = NULL;
    }
    /*----------------- Public Functions of Queue -----------------*/
    bool isEmpty() {
        return (head == NULL);
    }

    void enqueue(int data) {
        if(tail == NULL)
        {
            head = new Node(data);
            tail = head;
            return;
        }
        tail->next = new Node(data);
        tail = tail->next;
    }

    int dequeue() {
        if(isEmpty())
            return -1;
        
        int val = head->val;
        head = head->next;
        if(head == NULL)
        {
            tail = NULL;
        }
        return val;
    }

    int front() {
        if(isEmpty())
            return -1;
        
        return head->val;
    }
};