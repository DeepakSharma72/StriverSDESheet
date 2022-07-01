int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> Mat(n+1,vector<int>(n+1,1e9));
    for(int i=0;i<=n;i++)
    {
        Mat[i][i] = 0;
    }
    for(auto it:edges)
    {
        Mat[it[0]][it[1]] = it[2];
    }
    for(int node = 1;node <= n;node++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j =0;j<=n;j++)
            {
                if((Mat[i][node] + Mat[node][j] < Mat[i][j]) && (Mat[i][node] != 1e9 && Mat[node][j] != 1e9))
                {
                    Mat[i][j] = Mat[i][node] + Mat[node][j];
                }
            }
        }
    }
    return Mat[src][dest];
}