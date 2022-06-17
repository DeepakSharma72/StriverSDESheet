#include<stack>
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<int> S,minS;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
            S.push(num);
            if(minS.empty() || minS.top() >= num)
                minS.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if(S.empty())
                return -1;
            
            int val = S.top();
            S.pop();
            if(minS.top() == val)
                minS.pop();
            return val;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
            if(S.empty())
                return -1;
            return S.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
            if(minS.empty())
                return -1;
            return minS.top();
		}
};