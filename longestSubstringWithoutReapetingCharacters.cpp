#include <bits/stdc++.h> 
using namespace std;

int uniqueSubstrings(string input)
{
    int n = input.size();
    int cur = 1, prev = 1;
    int ans = 1;
    unordered_map<char,int> vis;
    vis[input[0]] = 0;
    for(int i=1;i<n;i++)
    {
        if(vis.find(input[i]) == vis.end())
        {
            cur = prev + 1;
        }
        else
        {
            cur = min(prev + 1,i-vis[input[i]]);
        }
        ans = max(ans,cur);
        prev = cur;
        vis[input[i]] = i;
    }
    return ans;
}