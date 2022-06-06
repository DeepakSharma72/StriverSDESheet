#include <bits/stdc++.h> 
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    int val1 = -1,val2 = -1;
    int ct1 = 0,ct2 = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(val1 == arr[i])
        {
            ct1++;
        }
        else if(val2 == arr[i])
        {
            ct2++;
        }
        else if(ct1 == 0)
        {
            val1 = arr[i];
            ct1 = 1;
        }
        else if(ct2 == 0)
        {
            val2 = arr[i];
            ct2 = 1;
        }
        else
        {
            ct1--,ct2--;
        }
    }
    vector<int> ans;
    ct1 = 0,ct2 = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] == val1)
        {
            ct1++;
        }
        if(arr[i] == val2)
        {
            ct2++;
        }
    }
    if(ct1 > arr.size()/3)
    {
        ans.push_back(val1);
    }
    if(ct2 > arr.size()/3)
    {
        ans.push_back(val2);
    }
    sort(ans.begin(),ans.end());
    return ans;
}