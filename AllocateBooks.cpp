long long dayCounter(long long time,vector<int> v)
{
    long long day = 1;
    long long cap = 0;
    for(auto it:v)
    {
        if(cap + it <= time)
        {
            cap += it;
        }
        else
        {
            cap = it;
            day++;
        }
    }
    return day;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{   
    long long lo = 0,hg = 0;
    for(auto it:time)
    {
        if(lo < it)
            lo = it;
        hg += it;
    }
    long long ans = hg;
    while(lo <= hg)
    {
        long long mid = (lo + hg)/2;
        if(dayCounter(mid,time) <= n)
        {
            if(ans > mid)
                ans = mid;
            hg = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    return ans;
}