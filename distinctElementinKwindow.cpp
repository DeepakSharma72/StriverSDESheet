#include<map>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    map<int,int> mp;
    for(int i=0;i<k;i++)
    {
        mp[arr[i]]++;
    }
    vector<int> ans;
    ans.push_back(mp.size());
    for(int i=k;i<arr.size();i++)
    {
        mp[arr[i]]++;
        mp[arr[i-k]]--;
        if(mp[arr[i-k]] == 0)
        {
            mp.erase(arr[i-k]);
        }
        ans.push_back(mp.size());
    }
    return ans;
}
