#include<bits/stdc++.h>

void getuniqueSubsets(vector<int> &arr,int n,int ind,vector<int> &v,vector<vector<int>> &ans)
{
    if(ind == n)
    {
        ans.push_back(v);
        return;
    }
    int j = ind+1;
    while(j < n && arr[j] == arr[j-1])
    {
        j++;
    }
    getuniqueSubsets(arr,n,j,v,ans);
    v.push_back(arr[ind]);
    getuniqueSubsets(arr,n,ind+1,v,ans);
    v.pop_back();
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> v;
    getuniqueSubsets(arr,n,0,v,ans);
    sort(ans.begin(),ans.end());
    return ans;
}