#include<stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> s;
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        if(s.size())
        {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}