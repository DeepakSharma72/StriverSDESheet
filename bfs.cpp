#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> temp;
    vector<vector<int>> G(vertex);
    for(auto it:edges)
    {
        G[it.first].push_back(it.second);
        G[it.second].push_back(it.first);
    }
//     for(auto it:G){
//         sort(it.begin(),it.end());
//     }
    vector<bool> vis(vertex,false);
            queue<int> q;
//             vector<int> temp;
    for(int i=0;i<vertex;i++)
    {
        if(vis[i] == false)
        {
            q.push(i);
            temp.push_back(i);
            vis[i] = true;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                sort(G[node].begin(),G[node].end());
                for(auto it:G[node])
                {
                    if(vis[it] == false)
                    {
                        vis[it] = true;
                        temp.push_back(it);
                        q.push(it);
                    }
                }
            }
        }
    }
    return temp;
}