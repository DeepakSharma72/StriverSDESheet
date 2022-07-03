int cutRod(vector<int> &price, int n)
{
    vector<int> DP(n+1,0);
    for(int i=1;i<=n;i++)
    {
        DP[i] = price[i-1];
    }
    for(int j=2;j<=n;j++)
    {
        for(int i=1;i<j;i++)
        {
            int len = j-i;
            DP[j] = max(DP[j],price[len-1] + DP[i]);
        }
    }
    return DP[n];
}
