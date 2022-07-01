#include<algorithm>
int getparent(int node,vector<int> &parent)
{
    if(parent[node] == node)
        return node;
    else
        return parent[node] = getparent(parent[node],parent);
}

void makeParent(int u,int v,vector<int> &parent,vector<int> &rank)
{
    u = getparent(u,parent);
    v = getparent(v,parent);
    if(rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if(rank[v] > rank[u])
    {
        parent[u] = v;
    }
    else
    {
        rank[u]++;
        parent[v] = u;
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    sort(graph.begin(),graph.end(),[&](vector<int> a,vector<int> b){
       return (a[2]<b[2]); 
    });
    vector<int> rank(n+1,0);
    vector<int> parent(n+1,0);
    for(int i=0;i<=n;i++)
    {
        parent[i] = i;
    }
    int ans = 0;
    for(auto it:graph)
    {
        int node1 = it[0];
        int node2 = it[1];
        int wgt = it[2];
        node1 = getparent(node1,parent);
        node2 = getparent(node2,parent);
        if(node1 != node2)
        {
            makeParent(node1,node2,parent,rank);
            ans += wgt;
        }
    }
    return ans;
}