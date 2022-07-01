#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    map<pair<int,int>,int> list;
    for(auto it:g)
    {
        int node1 = min(it.first.first,it.first.second);
        int node2 = max(it.first.second,it.first.first);
        if(node1 == node2)
        {
            continue;
        }
        if(list.find({node1,node2}) == list.end())
        {
          list[{node1,node2}] = it.second;   
        }
        else
        {
            list[{node1,node2}] = min(it.second,list[{node1,node2}]);
        }
    }
    vector<vector<pair<int,int>>> G(n+1);
    for(auto it:list)
    { // wgt,node
        G[it.first.first].push_back({it.second,it.first.second});
        G[it.first.second].push_back({it.second,it.first.first});
    }
    vector<bool> vis(n+1,false);
    vector<pair<pair<int,int>,int>> ans;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vis[1] = true;
    for(auto it:G[1])
    {
        pq.push({it.first,{1,it.second}});
    }
    int ctr = 1;
    while(!pq.empty() && ctr < n)
    {
        ctr++;
//         cout<<
        int curwgt = pq.top().first;
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second; // node1 -> node2
        pq.pop();
        if(vis[node1] && vis[node2])
        {
            ctr--;
            continue;
        }
//         cout<<node1<<" - "<<node2<<endl;
        pair<int,int> e = {node1,node2};
        ans.push_back({e,curwgt});
        
        int node = (vis[node1]?node2:node1);
        vis[node] = true;
        for(auto it:G[node])
        {
            if(vis[it.second] == false)
            pq.push({it.first,{node,it.second}});
        }
    }
    return ans;
}
