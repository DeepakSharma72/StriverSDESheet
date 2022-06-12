#include<bits/stdc++.h>
set<vector<pair<int,int>>> S;
vector<vector<int>> res;
void solve(vector<int> &arr,int n,int k,int csum,int ind,vector<int> &v)
{
    if(csum == k && ind == n)
    {
        res.push_back(v);
    }
    if(ind >= n)
        return;
    
    solve(arr,n,k,csum,ind+1,v);
//     v.push_back({arr[ind],ind});
    v.push_back(arr[ind]);
    solve(arr,n,k,csum+arr[ind],ind+1,v);
    v.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    res.clear();
    vector<vector<int>> ans;
    vector<int> v;
//     vector<pair<int,int>> vt;
    solve(arr,n,k,0,0,v);
    
//     for(auto it:S)
//     {
//         v.clear();
//         for(auto i:it)
//         {
//             v.push_back(i.first);
//         }
//         ans.push_back(v);
//     }
//     S.clear();
//     return ans;
       return res;
}