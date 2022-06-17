#include<stack>
vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && price[s.top()] <= price[i])
            s.pop();
        ans[i] = (s.empty()?(i+1):(i-s.top()));
        s.push(i);
    }
    return ans;
}