#include<queue>
void findMedian(int *arr, int n)
{
    priority_queue<int,vector<int>> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<n;i++)
    {
        if(minHeap.size() > maxHeap.size())
        {
            if(minHeap.top() >= arr[i])
            {
                maxHeap.push(arr[i]);
            }
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }
        else
        {
            if(minHeap.size() == 0)
            {
                minHeap.push(arr[i]);
            }
            else if(maxHeap.top() <= arr[i])
            {
                minHeap.push(arr[i]);
            }
            else
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        if(minHeap.size() == maxHeap.size())
        {
            cout<<(minHeap.top() + maxHeap.top())/2<<" ";
        }
        else
        {
            cout<<minHeap.top()<<" ";
        }
    }cout<<endl;
}