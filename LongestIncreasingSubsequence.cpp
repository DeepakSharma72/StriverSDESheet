#include<vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> lis;
    for(int i=0;i<n;i++)
    {
        if(lis.size() == 0 || lis.back() < arr[i])
        {
            lis.push_back(arr[i]);
        }
        else
        {
            int idx = lower_bound(lis.begin(),lis.end(),arr[i]) - lis.begin();
            lis[idx] = arr[i];
        }
    }
    return lis.size();
}
