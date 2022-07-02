#include<vector>
long countWaysToMakeChange(int *coins, int n, int value)
{
    vector<vector<long>> DP(n+1,vector<long>(value+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=value;j++)
        {
            if(j < coins[i-1])
            {
                DP[i][j] = DP[i-1][j];
            }
            else if(j == coins[i-1])
            {
                DP[i][j] = 1 + DP[i-1][j];
            }
            else
            {
                DP[i][j] = DP[i-1][j] + DP[i][j-coins[i-1]];
            }
        }
    }
    return DP[n][value];
}