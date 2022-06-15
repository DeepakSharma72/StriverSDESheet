#include<queue>
class Stack {
   queue<int> q;
   public:
    Stack() {
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return !q.size();
    }

    void push(int element) {
        q.push(element);
        int val = q.size()-1;
        for(int i=0;i<val;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(isEmpty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if(isEmpty()) return -1;
        return q.front();
    }
};