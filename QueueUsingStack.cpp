#include<stack>
class Queue {
    stack<int> A,B;
    public:
    Queue() {
    }

    void enQueue(int val) {
        A.push(val);
    }

    int deQueue() {
        if(isEmpty()) return -1;
        if(B.size() == 0)
        {
            while(!A.empty())
            {
                B.push(A.top());
                A.pop();
            }
        }
        int val = B.top();
        B.pop();
        return val;
    }

    int peek() {
        if(isEmpty()) return -1;
        if(B.size() == 0)
        {
            while(!A.empty())
            {
                B.push(A.top());
                A.pop();
            }
        }
        return B.top();
    }

    bool isEmpty() {
        return !(A.size()||B.size());
    }
};