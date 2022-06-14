double median(vector<int> a, vector<int> b)
{
    if(a.size() > b.size())
    {
        return median(b,a);
    }
    int M = (a.size() + b.size())/2;
    int lo = 0, hg = a.size();
    while(lo <= hg)
    {
        int cuts = (lo + hg)/2;
        int c1 = cuts;
        int c2 = M - cuts;
        int l1 = (c1 == 0)?-1:a[c1-1];
        int l2 = (c2 == 0)?-1:b[c2-1];
        int r1 = (c1 == a.size())?1e9+1:a[c1];
        int r2 = (c2 == b.size())?1e9+1:b[c2];
        if(l1 <= r2 && l2 <= r1)
        {
            if((a.size() + b.size())%2)
                return min(r1,r2);
            double ans = (min(r1,r2) + max(l1,l2))/2.0;
            return ans;
        }
        else if(l1 > r2)
        {
            hg = cuts-1;
        }
        else
        {
            lo = cuts+1;
        }
    }
    return 1.0;
}
