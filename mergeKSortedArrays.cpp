#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>>&KArrays, int k)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(KArrays.size(),0);
    for(int i=0;i<KArrays.size();i++)
    {
        pq.push({KArrays[i][0],i});
    }
    vector<int> ans;
    while(!pq.empty())
    {
        int node = pq.top().first;
        int ind = pq.top().second;
        pq.pop();
        ans.push_back(node);
        if(vis[ind] < (KArrays[ind].size()-1))
        {
            vis[ind]++;
            pq.push({KArrays[ind][vis[ind]],ind});
        }
    }
    return ans;
}
