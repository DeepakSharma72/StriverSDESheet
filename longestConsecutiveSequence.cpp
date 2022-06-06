#include <bits/stdc++.h> 
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
//     int ans = 1;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]] = 1;
    }
    int ans = 1;
    for(int i=0;i<arr.size();i++)
    {
        if(mp.find(arr[i]-1) == mp.end())
        {
            int cans = 1;
            int cval = arr[i]+1;
            while(mp.find(cval) != mp.end())
            {
                cval++;
                cans++;
            }
            ans = max(ans,cans);
        }
    }
    return ans;
}