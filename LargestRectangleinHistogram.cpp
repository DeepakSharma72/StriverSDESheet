#include<stack> 
int largestRectangle(vector < int > & heights) {
   int n = heights.size();
        vector<int> left(n),right(n);
        int i=n-1;
        stack<int> s;
        while(i>=0)
        {
            while(!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            right[i] = (s.empty()?n:s.top());
            s.push(i);
            i--;
        }
        i = 0;
        
        while(!s.empty())
            s.pop();
        
        while(i < n)
        {
            while(!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            left[i] = (s.empty()?-1:s.top());
            s.push(i);
            i++;
        }
       
        int ans = 0;
        for(i=0;i<n;i++)
        {
            int val = heights[i]*(right[i] - left[i]-1);
            ans = max(val,ans);
        }
        return ans;
 }