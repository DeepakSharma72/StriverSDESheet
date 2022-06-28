#include<queue>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> G(n+1);
    for(auto it:edges)
    {
        G[it[0]].push_back(it[1]);
        G[it[1]].push_back(it[0]);
    }
    queue<pair<int,int>> q;
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(vis[i] == false)
        {
            q.push({i,-1});
            while(!q.empty())
            {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                vis[node] = true;
                for(auto it:G[node])
                {
                    if(vis[it] == true && it != parent)
                    {
                        return "Yes";
                    }
                    else if(vis[it] == false)
                    {
                        q.push({it,node});
                    }
                }
            }
        }
    }
    return "No";
}
