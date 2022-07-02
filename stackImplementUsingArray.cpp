// Stack class.
class Stack {
    int *arr;
    int idx;
    int size;
public:
    
    Stack(int capacity) {
        arr = new int[capacity];
        size = capacity;
        idx = 0;
    }

    void push(int num) {
        arr[idx++] = num;
    }

    int pop() {
        if(idx == 0)
            return -1;
        return arr[--idx];
    }
    
    int top() {
        if(idx == 0)
        {
            return -1;
        }
        return arr[idx-1];
    }
    
    int isEmpty() {
        return (idx == 0);
    }
    
    int isFull() {
        return (idx == size);
    }
    
};