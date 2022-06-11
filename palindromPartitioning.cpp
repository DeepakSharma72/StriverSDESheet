#include<bits/stdc++.h>

bool ispalindrome(string &temp)
{
    int i=0,j=temp.size()-1;
    while(i<j)
    {
        if(temp[i] != temp[j])
            return false;
        i++,j--;
    }
    return true;
}

void solve(string &s,int ind,vector<string> &v,vector<vector<string>> &ans)
{
    if(ind == s.size())
    {
        ans.push_back(v);
        return;
    }
    string temp = "";
    while(ind < s.size())
    {
        temp.push_back(s[ind]);
        if(ispalindrome(temp))
        {
            v.push_back(temp);
            solve(s,ind+1,v,ans);
            v.pop_back();
        }
        ind++;
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> v;
    solve(s,0,v,ans);
    return ans;
}