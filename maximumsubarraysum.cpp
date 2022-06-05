#include <bits/stdc++.h> 
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long ans = 0;
    long long csum = 0;
    int i = 0;
    while(i<n)
    {
        csum += arr[i];
        ans = max(ans,csum);
        if(csum < 0)
        {
            csum = 0;
        }
        i++;
    }
    return ans;
}