#include<bits/stdc++.h>

struct node{
    int ind,st,en;
    node(int i,int s,int e)
    {
        ind = i, st = s,en = e;
    }
};

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
//     vector<int> ans;
    vector<node> v;
    for(int i=0;i<end.size();i++)
    {
        v.push_back(node(i+1,start[i],end[i]));
    }
    sort(v.begin(),v.end(),[&](node a,node b){
       if(a.en == b.en)
           return a.ind < b.ind;
        else
            return a.en < b.en;
    });
    vector<int> ans;
    int timer = -1;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].st > timer)
        {
            timer = v[i].en;
            ans.push_back(v[i].ind);
        }
    }
    return ans;
}