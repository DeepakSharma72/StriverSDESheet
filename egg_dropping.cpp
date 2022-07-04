#include<bits/stdc++.h>

int DP[101][10001];

int help(int e,int fl)
{
    if(e == 0)
    {
        DP[e][fl] = 0;
        return 0;
    }
    if(e == 1 || fl <= 1)
    {
        DP[e][fl] = fl;
        return fl;
    }
    if(DP[e][fl] != -1)
    {
        return DP[e][fl];
    }
    int lo = 1,up = fl;
    int ans = INT_MAX;
    while(lo <= up)
    {
        int mid = (lo+up)/2;
        int go_down = help(e-1,mid-1);
        int go_up = help(e,fl-mid);
        ans = min(ans,max(go_down,go_up) + 1);
        if(go_up > go_down)
        {
            lo = mid+1;
        }
        else
        {
            up = mid-1;
        }
    }
    return DP[e][fl] = ans;
}


int cutLogs(int k, int n)
{
    memset(DP,-1,sizeof(DP));
    return help(k,n);
}
