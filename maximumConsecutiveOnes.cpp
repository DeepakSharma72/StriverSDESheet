#include<bits/stdc++.h>

int longestSubSeg(vector<int> &arr , int n, int k){
    unordered_map<int,int> mp;
    int ctr = 0;
    int ans = 0;
    mp[0] = -1;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            ctr++;
            if(mp.find(ctr) == mp.end())
                mp[ctr] = i;
        }
        int ind = max(0,ctr-k);
        ans = max(ans,i-mp[ind]);
    }
    return ans;
}
