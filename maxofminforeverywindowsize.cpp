#include<stack>
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans(n,-1e9-1);
    vector<int> left(n),right(n);
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        left[i] = (s.empty()?-1:s.top());
        s.push(i);
    }
    
    while(!s.empty())
        s.pop();
    
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && a[s.top()] >= a[i])
            s.pop();
        right[i] = (s.empty()?n:s.top());
        s.push(i);
    }
    
    for(int i=0;i<n;i++)
    {
        int val = (right[i] - left[i] - 2);
        ans[val] = max(ans[val],a[i]);
    }
    
    for(int i=n-2;i>=0;i--)
    {
        ans[i] = max(ans[i],ans[i+1]);
    }
    return ans;
}