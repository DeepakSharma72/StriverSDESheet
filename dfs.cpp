void dfs(int node,vector<bool> &vis,vector<vector<int>> &adj,vector<int> &temp)
{
    vis[node] = true;
    temp.push_back(node);
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,temp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
     vector<vector<int>> adj(V);
     for(auto it:edges)
     {
         adj[it[0]].push_back(it[1]);
         adj[it[1]].push_back(it[0]);
     }
    vector<bool> vis(V,false);
    vector<vector<int>> ans;
     for(int i=0;i<V;i++)
     {
         if(!vis[i])
         {
             vector<int> temp;
             dfs(i,vis,adj,temp);
             ans.push_back(temp);
         }
     }
    return ans;
}