#include <bits/stdc++.h> 
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int mis = -1,dup = -1;
    for(int i=0;i<n;i++)
    {
        int val = abs(arr[i])-1;
        if(arr[val] < 0)
        {
            dup = val+1;
        }
        else
        {
            arr[val] *= -1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i] > 0)
        {
            mis = i+1;
            break;
        }
    }
    return {mis,dup};
}
