#include <bits/stdc++.h> 
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<long long,int> mp;
    mp[0] = 1;
    long long sum = 0;
    int ans = 0;
    for(int i=0;i<arr.size();i++)
    {
        sum ^= arr[i];
        long long val = (sum^x);
        if(mp.find(val) != mp.end())
        {
            ans += mp[val];
        }
        mp[sum]++;
    }
    return ans;
}