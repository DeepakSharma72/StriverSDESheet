int Counter(int tar,vector<vector<int>> &mat)
{
    int ans = 0;
    for(int i=0;i<mat.size();i++)
    {   
        if(mat[i][0] > tar)
        {
            continue;
        }
        else if(mat[i][mat[i].size()-1] <= tar)
        {
            ans += mat[i].size();
        }
        else
        {
            int lo = 0, hg = mat[i].size()-1;
            int temp = 0;
            while(lo <= hg)
            {
                int mid = (lo + hg)/2;
                if(mat[i][mid] <= tar)
                {
                    temp = max(temp,mid+1); 
                    lo = mid+1;
                }
                else
                {
                    hg = mid-1;
                }
            }  
            ans += temp;
           }
    }
    return ans;
}

int getMedian(vector<vector<int>> &matrix)
{
    int lo = 1;
    int hg = 1e5;
    int R = matrix.size(), C = matrix[0].size();
    int ans = hg;
    int Median = (R*C)/2 + 1;
    while(lo <= hg)
    {
        int mid = (lo + hg)/2;
        int C = Counter(mid,matrix);
        if(C >= Median)
        {
            ans = min(ans,mid);
            hg = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    return ans;
}