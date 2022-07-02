
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> DP(N,vector<int>(N,0));
    for(int gp = 2;gp < N;gp++)
    {
        for(int i=0,j=gp;j<N;j++,i++)
        {
            if(gp == 2)
            {
                DP[i][j] = arr[i]*arr[i+1]*arr[j];
            }
            else
            {
                int temp = 1e9+7;
                for(int k=i+1;k<j;k++)
                {
                    int val = DP[i][k] + DP[k][j] + (arr[i]*arr[k]*arr[j]);
                    temp = min(temp,val);
                }
                DP[i][j] = temp;
            }
        }
    }
    return DP[0][N-1];
}