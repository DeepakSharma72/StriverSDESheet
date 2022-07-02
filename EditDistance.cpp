int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> DP(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)
    {
        DP[i][0] = i;
    }
    for(int j=0;j<=m;j++)
    {
        DP[0][j] = j;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                DP[i][j] = DP[i-1][j-1];
            }
            else
            {
                DP[i][j] = min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1])) + 1;
            }
        }
    }
    return DP[n][m];
}