#include<stack>

void getTopo(int node,vector<vector<int>> &G,stack<int> &s,vector<bool> &vis)
{
    vis[node] = true;
    for(auto it:G[node])
    {
        if(vis[it] == false)
        getTopo(it,G,s,vis);
    }
    s.push(node);
}

void revdfs(int node,vector<bool> &vis,vector<int> &v,vector<vector<int>> &G)
{
    vis[node] = true;
    v.push_back(node);
    for(auto it:G[node])
    {
        if(vis[it] == false)
        {
            revdfs(it,vis,v,G);
        }
    }    
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    stack<int> s;
    vector<vector<int>> G(n);
    vector<vector<int>> rG(n);
    for(int i=0;i<edges.size();i++)
    {
        G[edges[i][0]].push_back(edges[i][1]);
        rG[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++)
    {
        if(vis[i] == false)
        {
          getTopo(i,G,s,vis);       
        }
    }
    for(int i=0;i<n;i++)
    {
        vis[i] = false;
    }
    vector<vector<int>> ans;
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
//         cout<<node<<" - "<<vis[node]<<endl;
        if(vis[node] == false)
        {
            vector<int> v;
            revdfs(node,vis,v,rG);
            sort(v.begin(),v.end());
            ans.push_back(v);
        }
    }
return ans;    
}