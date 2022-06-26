#include<queue>
vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int,vector<int>> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(maxHeap.size() == minHeap.size())
        {
            if(!minHeap.empty()  && minHeap.top() < arr[i])
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(arr[i]);
            }
            else
            {
                maxHeap.push(arr[i]);
            }
            ans.push_back(maxHeap.top());
        }
        else
        {
            if(!maxHeap.empty() && maxHeap.top() > arr[i])
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
            else
            {
                minHeap.push(arr[i]);
            }
            int val = (minHeap.top() + maxHeap.top())/2;
            ans.push_back(val);
        }
//         cout<<ans.back()<<" ";
    }
    return ans;
}
