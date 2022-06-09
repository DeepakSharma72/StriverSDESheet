#include <bits/stdc++.h> 
void LeftFill(long *arr,vector<long> &left)
{
    stack<long> s;
    for(int i=0;i<left.size();i++)
    {
        while(!s.empty() && arr[s.top()] <= arr[i])
            s.pop();
        if(s.empty() || arr[s.top()] < arr[i])
            s.push(i);
        left[i] = s.top();
    }
}

void RightFill(long *arr,vector<long> &right)
{
    stack<long> s;
    for(int i=right.size()-1;i>=0;i--)
    {
        while(!s.empty() && arr[s.top()] <= arr[i])
            s.pop();
        if(s.empty() || arr[s.top()] < arr[i])
            s.push(i);
        right[i] = s.top();
    }
}


long getTrappedWater(long *arr, int n){
    vector<long> left(n),right(n);
    LeftFill(arr,left);
    RightFill(arr,right);
    long ans = 0;
    for(int i=0;i<n;i++)
    {
        long h = min(arr[left[i]],arr[right[i]]) - arr[i];
        ans += h;
    }
    return ans;
}