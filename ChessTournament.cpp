int roomCounter(int gap,vector<int> positions)
{
    int room = 1;
    int gp = positions[0];
    for(auto it:positions)
    {
        if(it - gp >= gap)
        {
            gp = it;
            room++;
        }
    }
    return room;
}

int chessTournament(vector<int> positions , int n ,  int c){
    sort(positions.begin(),positions.end());
    int lo = 1,hg = positions[n-1] - positions[0];
    int ans = 0;
    while(lo <= hg)
    {
        int gap = (lo + hg)/2;
        if(roomCounter(gap,positions) >= c)
        {
            ans = max(gap,ans);
            lo = gap+1;
        }
        else
        {
            hg = gap-1;
        }
    }
    return ans;
}