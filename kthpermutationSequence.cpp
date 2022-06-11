void solve(string &ans,vector<bool> &vis,int k,int n,int csz,int curctr,int ind)
{
    int getmax = 1;
    for(int i=1;i<csz;i++)
    {
        getmax *= i;
    }
    
    if(getmax + curctr >= k)
    {
        ans.push_back(ind + '0');
        vis[ind] = true;
        int j = 1;
        while(j <= n && vis[j] == true)
            j++;
        if(j <= n)
        solve(ans,vis,k,n,csz-1,curctr,j);
    }
    else
    {
        int j = ind+1;
        while(vis[j] == true)
            j++;
        solve(ans,vis,k,n,csz,curctr+getmax,j);
    }
}
string kthPermutation(int n, int k) {
    vector<bool> vis(n+1,false);
    string ans = "";
    solve(ans,vis,k,n,n,0,1);
    return ans;
}
