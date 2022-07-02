int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> DP(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(weights[i-1] > j)
            {
                DP[i][j] = DP[i-1][j];
            }
            else{
                int idx = j - weights[i-1];
                int tot = (values[i-1] + DP[i-1][idx]);
                DP[i][j] = max(DP[i-1][j], tot);
            }
        }
    }
    return DP[n][w];
}