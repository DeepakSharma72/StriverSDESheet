// bfs
#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    vector<int> In(v,0);
    vector<vector<int>> G(v);
    for(auto it:edges)
    {
        G[it[0]].push_back(it[1]);
        In[it[1]]++;
    }
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(In[i] == 0)
           q.push(i); 
    }
    while(!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto it:G[node])
        {
            In[it]--;
            if(In[it] == 0)
                q.push(it);
        }
    }
    
    return ans;
}

// dfs

void dfs(int node,vector<int> &In,vector<bool> &vis,vector<int> &ans,vector<vector<int>> &G)
{
    ans.push_back(node);
    vis[node] = true;
    for(auto it:G[node])
    {
        In[it]--;
        if(In[it] == 0)
        {
            dfs(it,In,vis,ans,G);
        }
    }
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> In(v,0);
    vector<vector<int>> G(v);
    
    for(auto it:edges)
    {
        G[it[0]].push_back(it[1]);
        In[it[1]]++;
    }
    vector<int> ans;
    vector<bool> vis(v,false);
    for(int i=0;i<v;i++)
    {
        if(In[i] == 0 && vis[i] == false)
        {
            dfs(i,In,vis,ans,G);
        }
    }
    return ans;
}