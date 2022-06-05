#include <bits/stdc++.h>
using namespace std; 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    int n = intervals.size();
    for(int i=0;i<n;i++)
    {
        int lo = intervals[i][0],hg = intervals[i][1];
        if(ans.size() == 0 || ans.back()[1] < lo)
            ans.push_back({lo,hg});
        else
        {
           ans[ans.size()-1][0] = min(ans[ans.size()-1][0],lo);
           ans[ans.size()-1][1] = max(ans[ans.size()-1][1],hg);
        }
    }
    return ans;
}
