void getpowerset(int idx,vector<int> &cv,vector<int> &v,vector<vector<int>> &ans)
{
    if(idx == v.size())
    {
        ans.push_back(cv);
    }
    else
    {
        getpowerset(idx+1,cv,v,ans);
        cv.push_back(v[idx]);
        getpowerset(idx+1,cv,v,ans);
        cv.pop_back();
    }
}

vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    vector<int> cv;
    getpowerset(0,cv,v,ans);
    return ans;
}