bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> DP(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        DP[i][0] = 1;
        DP[i][arr[i]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (DP[i - 1][j] == true)
            {
                if (j + arr[i] <= k)
                    DP[i][j + arr[i]] = true;

                DP[i][j] = true;
            }
        }
    }
    return DP[n - 1][k];
}