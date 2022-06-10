void getSubsetSum(vector<int> &num,int ind,vector<int> &ans,int csf)
{
    if(ind == num.size())
    {
         ans.push_back(csf);
         return;
    }

    getSubsetSum(num,ind+1,ans,csf);
    getSubsetSum(num,ind+1,ans,csf + num[ind]);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    getSubsetSum(num,0,ans,0);
    sort(ans.begin(),ans.end());
    return ans;
}