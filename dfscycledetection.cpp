bool dfs(int node,int parent,vector<vector<int>> &G,vector<bool> &vis)
{
    vis[node] = true;
    for(auto it:G[node])
    {
        if(vis[it] == true && it != parent)
            return true;
        else if(vis[it] == false)
        {
            if(dfs(it,node,G,vis))
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> G(n+1);
    for(auto it:edges)
    {
        G[it[0]].push_back(it[1]);
        G[it[1]].push_back(it[0]);
    }
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(vis[i] == false)
        {
          if(dfs(i,-1,G,vis))
          return "Yes";   
        }
    }
    return "No";    
}

