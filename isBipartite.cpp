// dfs
bool dfs(int node,vector<int> &color,vector<vector<int>> &edges)
{
    for(int i=0;i<edges.size();i++)
    {
        if(edges[node][i] == 1)
        {
            if(color[i] == -1)
            {
                color[i] = 1 - color[node];
                if(!dfs(i,color,edges))
                    return false;
            }
            else if(color[node] == color[i]){
                return false;
            }
        }
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
    for(int i=0;i<edges.size();i++)
    {
        for(int j=0;j<edges.size();j++)
        {
            if(edges[i][j] == 1)
            {
                edges[j][i] = 1;
            }
        }
    }
    vector<int> color(edges.size(),-1);
    color[0] = 0;
    return dfs(0,color,edges);
}

// bfs
#include<queue>
bool isGraphBirpatite(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<int> color(n,-1);
    for(int i=0;i<n;i++)
    {
        if(color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while(!q.empty())
            {
                int r = q.front();
                q.pop();
                for(int c=0;c<n;c++)
                {
                    if(mat[r][c] == 1)
                    {
                        if(color[r] == color[c])
                            return false;
                        else if(color[c] == -1)
                        {
                            color[c] = 1 - color[r];
                            q.push(c);
                        }
                    }
                }
            }
        }
    }
    return true;
}