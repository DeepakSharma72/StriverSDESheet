bool dfs(int node,vector<bool> &vis,vector<bool> &dfsvis,vector<vector<int>> &G)
{
    vis[node] = dfsvis[node] = true;
    for(auto it:G[node])
    {
        if(vis[it] == true && dfsvis[it] == true)
        {
            return true;
        }
        else if(vis[it] == false)
        {
            if(dfs(it,vis,dfsvis,G))
                return true;
        }
    }
    dfsvis[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> G(n+1);
    for(auto it:edges)
    {
        G[it.first].push_back(it.second);
    }
    vector<bool> vis(n+1,false),dfsvis(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(vis[i] == false)
        {
           if(dfs(i,vis,dfsvis,G))
               return true;
        }
    }
    return false;
}