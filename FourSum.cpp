#include <bits/stdc++.h> 
using namespace std;

bool isequal(int i,int j,int k,int l)
{
    if(i == j || i == k || i == l || j == k || j == l || k == l)
        return true;
    return false;
}

string fourSum(vector<int> arr, int target, int n) {
    unordered_map<int,pair<int,int>> mp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int tsum = arr[i] + arr[j]; 
            mp[tsum] = {i,j};
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int tsum = arr[i] + arr[j];
            tsum = target - tsum;
            if(mp.find(tsum) != mp.end() && !isequal(i,j,mp[tsum].first,mp[tsum].second))
            {
                return "Yes\n";
            }
        }
    }
    return "No";
}
