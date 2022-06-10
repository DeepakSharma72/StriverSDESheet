#include<bits/stdc++.h>
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(),jobs.end());
    priority_queue<int,vector<int>,greater<int>> profits;
    for(int i=0;i<jobs.size();i++)
    {
        if(profits.size() < jobs[i][0])
        {
            profits.push(jobs[i][1]);
        }
        else
        {
            if(profits.top() < jobs[i][1])
            {
                profits.pop();
                profits.push(jobs[i][1]);
            }
        }
    }
    int ans = 0;
    while(!profits.empty())
    {
        ans += profits.top();
        profits.pop();
    }
    return ans;
}
