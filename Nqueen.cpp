bool isvalid(vector<int> &Mat,int ind,int n)
{
    if(n == 1)
    {
        return !Mat[0];
    }
    
    int j = ind;
    while(j >= 0)
    {
        if(Mat[j] == 1)
            return false;
        j -= n;
    }
    int ccol = min(1 + ind%n,ind/n + 1);
    j = ind;
    while(ccol--)
    {
        if(Mat[j] == 1) return false;
        j -= (n+1);
    }
    ccol = min(ind/n + 1,n - ind%n);
    j = ind;
    while(ccol--)
    {
        if(Mat[j] == 1) return false;
        j -= (n-1);
    }
    return true;
}

void Nqueen(int n,int crow,vector<int> &Mat,vector<vector<int>> &Result)
{
    if(crow == n)
    {
        Result.push_back(Mat);
        return;
    }
    for(int c = crow*n;c <= (n*(crow+1) - 1);c++)
    {
        if(isvalid(Mat,c,n))
        {
            Mat[c] = 1;
            Nqueen(n,crow+1,Mat,Result);
            Mat[c] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<int> Mat(n*n,0);
    vector<vector<int>> res;
    Nqueen(n,0,Mat,res);
    return res;
}