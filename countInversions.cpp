#include <bits/stdc++.h> 
using namespace std;

long long merge(long long *&arr,int lo,int mid,int hg)
{
    long long ans = 0;
    long long *A = new long long[mid-lo+1];
    long long *B = new long long[hg-mid];
    int SA = mid - lo + 1;
    int SB = hg - mid;
    for(int i = 0;i<SA;i++)
    {
        A[i] = arr[lo+i];
    }
    for(int j=0;j<SB;j++)
    {
        B[j] = arr[j + mid + 1];
    }
    
    int i = 0,j=0,k = lo;
    while(i < SA && j<SB)
    {
        if(A[i] > B[j])
        {
            ans += (SA - i);
            arr[k++] = B[j++];
        }
        else
        {
            arr[k++] = A[i++];
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

long long mergeSort(long long *&arr,int lo,int up)
{
    if(lo >= up)
        return 0;
    int mid = (lo + up)/2;
    long long A = mergeSort(arr,lo,mid);
    long long B = mergeSort(arr,mid+1,up);
    long long C = merge(arr,lo,mid,up);
    return (A+B+C);
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr,0,n-1);
}