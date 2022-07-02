#include<vector>
int lcs(string s, string t)
{
    int m = s.length();
    int n = t.length();
    vector<vector<int>> DP(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1] == t[j-1])
            {
                DP[i][j] = 1 + DP[i-1][j-1];
            }
            else
            {
                DP[i][j] = max(DP[i][j-1],DP[i-1][j]);
            }
        }
    }
    return DP[m][n];
}