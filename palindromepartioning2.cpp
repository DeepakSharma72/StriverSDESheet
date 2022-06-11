#include<bits/stdc++.h>

int palindromePartitioning(string str) {
    vector<vector<bool>> DP(str.size(),vector<bool>(str.size(),0));
    for(int gp=0;gp<str.size();gp++)
    {
        for(int i=0,j=gp;j<str.size();j++,i++)
        {
            if(gp == 0)
            {
                DP[i][j] = true;
            }
            else if(gp == 1 && str[i] == str[j])
            {
                DP[i][j] = true;
            }
            else if(gp > 1 && str[i] == str[j] && DP[i+1][j-1])
            {
                DP[i][j] = true;
            }
        }
    }
    
    
    int ans = str.size()-1;
    queue<pair<int,int>> q;
    for(int i=0;i<str.size();i++)
    {
        if(DP[0][i])
        {
            q.push({i+1,0});
        }
    }
    
    while(!q.empty())
    {
        int cuts = q.front().second;
        int ind = q.front().first;
        q.pop();
        if(ind == str.size())
        {
            ans = cuts;
            break;
        }
        for(int i=str.size()-1;i>=ind;i--)
        {
            if(DP[ind][i])
            {
                q.push({i+1,cuts+1});
            }
        }
    }
    
    return ans;
}
