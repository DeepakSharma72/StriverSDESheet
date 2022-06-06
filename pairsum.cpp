#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   unordered_map<int,int> key;
    vector<vector<int>> ans;
   for(int i=0;i<arr.size();i++)
   {
           for(int j=0;j<key[s-arr[i]];j++)
           {
               int mn = min(s-arr[i],arr[i]);
               int mx = max(s-arr[i],arr[i]);
               ans.push_back({mn,mx});
           }
         key[arr[i]]++;
   }
    sort(ans.begin(),ans.end());
    return ans;
}