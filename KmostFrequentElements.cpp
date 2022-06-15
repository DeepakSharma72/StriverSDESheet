#include<queue>
#include<unordered_map>
#include<algorithm>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int> mp;
    for(auto it:arr)
    {
        mp[it]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
    for(auto it:mp)
    {
        pq.push({it.second,it.first});
    }
    vector<int> ans;
    while(k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
 }