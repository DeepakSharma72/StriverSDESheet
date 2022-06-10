#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> v;
    int n = start.size();
    for(int i=0;i<n;i++)
    {
        v.push_back({start[i],finish[i]});
    }
    sort(v.begin(),v.end(),[&](pair<int,int> a,pair<int,int> b){
          return (a.second<b.second); 
    });
    
    int timer = -1;
    int ctr = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i].first >= timer)
        {
            ctr++;
            timer = v[i].second;
        }
    }
    return ctr;
}