#include <bits/stdc++.h> 
using namespace std;

int merge(vector<int> &arr,int lo,int mid,int hg)
{
    int ans = 0;
    int SA = mid - lo + 1;
    int SB = hg - mid;
    vector<int> A(SA),B(SB);
    for(int i=0;i<SA;i++)
    {
        A[i] = arr[lo + i];
    }
    for(int j=0;j<SB;j++)
    {
        B[j] = arr[mid + 1 + j];
    }
    for(int j=0;j<SB;j++)
    {
        int tar = B[j]*2;
        int low = 0, high = SA;
        int ind = SA;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(A[mid] > tar)
            {
                ind = min(ind,mid);
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        ans += (SA - ind);
    }
    
    int i = 0,j = 0,k = lo;
    while(i < SA && j < SB)
    {
        if(A[i] <= B[j])
        {
            arr[k++] = A[i++];
        }
        else
        {
            arr[k++] = B[j++];
        }
    }
    while(i < SA)
    {
        arr[k++] = A[i++];
    }
    while(j < SB)
    {
        arr[k++] = B[j++];
    }
    return ans;
}

int mergeSort(vector<int> &arr,int lo,int hg)
{
    if(lo >= hg)
        return 0;
    int mid = (lo+hg)/2;
    return mergeSort(arr,lo,mid) + mergeSort(arr,mid+1,hg) + merge(arr,lo,mid,hg);
}

int reversePairs(vector<int> &arr, int n){
    return mergeSort(arr,0,n-1);
}