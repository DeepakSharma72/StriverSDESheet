#include<queue>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    deque<int> dq;
    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && dq.back() < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(nums[i]);
    }
    vector<int> ans;
    ans.push_back(dq.front());
    for(int i=k;i<nums.size();i++)
    {
        if(nums[i-k] == dq.front())
        {
            dq.pop_front();
        }
        while(!dq.empty() && dq.back() < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(nums[i]);
        ans.push_back(dq.front());
    }
    return ans;
}