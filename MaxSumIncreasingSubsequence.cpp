int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    vector<int> DP(n,0);
    DP[0] = rack[0];
    int ans = DP[0];
	for(int i=1;i<n;i++)
    {
        DP[i] = rack[i];
        for(int j=0;j<i;j++)
        {
            if(rack[j] < rack[i])
            {
                DP[i] = max(DP[i],DP[j] + rack[i]);
            }
        }
        ans = max(DP[i],ans);
    }
    return ans;
}