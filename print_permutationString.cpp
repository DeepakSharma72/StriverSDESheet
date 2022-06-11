void solve(string &s,int ctr,vector<bool> &vis,string &str,vector<string> &ans)
{
    if(ctr == s.size())
    {
        ans.push_back(str);
        return;
    }
    
    for(int i=0;i<s.size();i++)
    {
        if(vis[i] == false)
        {
            vis[i] = true;
            str.push_back(s[i]);
            solve(s,ctr+1,vis,str,ans);
            vis[i] = false;
            str.pop_back();
        }
    }
}
vector<string> findPermutations(string &s) {
    string str = "";
    vector<string> ans;
    vector<bool> vis(s.size(),false);
    solve(s,0,vis,str,ans);
    return ans;
}