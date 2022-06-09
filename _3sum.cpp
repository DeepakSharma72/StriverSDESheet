#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
	for(int i=0;i<n;i++)
    {
        if(i > 0 && arr[i] == arr[i-1]) continue;
        int tar = K - arr[i];
        int l = i+1,r = n-1;
        while(l<r)
        {
            if(arr[l] + arr[r] == tar)
            {
               ans.push_back({arr[i],arr[l],arr[r]});
                int L = arr[l], R = arr[r];
               while(l < r && arr[l] == L)
                l++;
               while(l < r && arr[r] == R)
                r--;
            }
            else if(arr[l] + arr[r] > tar)
                r--;
            else
                l++;
        }
    }
    return ans;
}