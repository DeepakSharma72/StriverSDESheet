int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(row1.size() > row2.size())
    {
        return ninjaAndLadoos(row2,row1,n,m,k);
    }
    m = row1.size();
    n = row2.size();
    int lo = max(0,k-m), hg = min(k,n);
    while(lo <= hg)
    {
        int cuts = (lo + hg)/2;
        int c1 = min(m,cuts);
        int c2 = k - c1;
        int l1 = (c1 == 0)?-1:row1[c1-1];
        int l2 = (c2 == 0)?-1:row2[c2-1];
        int r1 = (c1 == m)?1e5+1:row1[c1];
        int r2 = (c2 == n)?1e5+1:row2[c2];
        if(l1 <= r2 && l2 <= r1)
        {
            return max(l1,l2);
        }
        else if(l1 >= r2)
        {
             hg = cuts-1;
        }
        else
        {
            lo = cuts+1;
        }
    }
    return 0;
}