bool isValid(int clr,vector<int> &AdjList,vector<int> &color)
{
    for(int i=0;i<AdjList.size();i++)
    {
        if(AdjList[i] == 1 && color[i] == clr)
            return false;
    }
    return true;
}

bool isColoring(int node,vector<int> &color,vector<vector<int>> &G,int m)
{
    if(node >= color.size())
        return true;
    for(int i=0;i<m;i++)
    {
        if(isValid(i,G[node],color))
        {
            color[node] = i;
            if(isColoring(node+1,color,G,m))
            {
                return true;
            }
            color[node] = -1;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int> color(n,-1);
   bool ans = isColoring(0,color,mat,m);
    return (ans == true)?"YES":"NO";
}