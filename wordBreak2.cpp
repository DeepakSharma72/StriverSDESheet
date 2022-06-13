#include<bits/stdc++.h>

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    set<string> st;
    for(auto it:dictionary)
    {
        st.insert(it);
    }
    
    string temp = "";
    queue<pair<string,int>> q;
    for(int i=0;i<s.size();i++)
    {
        temp.push_back(s[i]);
        if(st.find(temp) != st.end())
        {
            q.push({temp,i+1});
        }
    }
    vector<string> res;
    while(!q.empty())
    {
        string curstr = q.front().first;
        int cind = q.front().second;
        q.pop();
        if(cind == s.size())
        {
            res.push_back(curstr);
        }
        else
        {
            temp = "";
            for(int i=cind;i<s.size();i++)
            {
                temp.push_back(s[i]);
                if(st.find(temp) != st.end())
                {
                    string pass = curstr + " " + temp;
                    q.push({pass,i+1});
                }
            }
        }
    }
return res;
}