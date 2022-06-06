#include <bits/stdc++.h>
using namespace std;
 
int LongestSubsetWithZeroSum(vector < int > arr) {
    int ans = 0;
    int sum = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        sum += arr[i];
        if(sum == 0)
        {
            ans = i+1;
            continue;
        }
        if(mp.find(sum) != mp.end())
        {
            ans = max(ans, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
return ans;
}#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    int ans = 0;
    int sum = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        sum += arr[i];
        if(sum == 0)
        {
            ans = i+1;
            continue;
        }
        if(mp.find(sum) != mp.end())
        {
            ans = max(ans, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
return ans;
}