#include<bits/stdc++.h>
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
   sort(items.begin(),items.end(),[&](pair<int,int> a,pair<int,int> b){
       double A = (double)a.second/a.first;
       double B = (double)b.second/b.first;
       return A>B;
   });
    int W = 0;
    double ans = 0;
    for(int i=0;i<n;i++)
    {
        if(items[i].first + W <= w)
        {
            ans += items[i].second;
            W += items[i].first;
        }
        else
        {
            double fraction = (double)items[i].second/items[i].first;
            ans += fraction*(w-W);
            W = w;
        }
    }
    return ans;
}