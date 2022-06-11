#include<bits/stdc++.h>

void solve(vector<int> &arr,int i,int n,int target,vector<int> &v,vector<vector<int>> &S)
{
    if(target == 0)
    {
        S.push_back(v);
        return;
    }
    if(target < 0 || i == n)
        return;
    int j = i+1;
    while(j < n && arr[j] == arr[i])
        j++;
    if(j<n)
    solve(arr,j,n,target,v,S);
    v.push_back(arr[i]);
    solve(arr,i+1,n,target-arr[i],v,S);
    v.pop_back();
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(),arr.end());
    vector<int> v;
    vector<vector<int>> ans;
    solve(arr,0,n,target,v,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
