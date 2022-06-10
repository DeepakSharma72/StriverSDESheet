#include<bits/stdc++.h>

int calculateMinPatforms(int at[], int dt[], int n) {
    int ans = 1;
    sort(at,at+n);
    sort(dt,dt+n);
    int a = 1,d = 0;
    while(a < n)
    {
        while(d < n && dt[d] < at[a])
        {
            d++;
        }
        a++;
        ans = max(a-d,ans);
    }
    return ans;
}