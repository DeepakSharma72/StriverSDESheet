#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int ind = -1;
    for(int i=n-1;i>0;i--)
    {
        if(permutation[i-1] < permutation[i])
        {
            ind = i-1;
            break;
        }
    }
    if(ind == -1)
    {
        sort(permutation.begin(),permutation.end());
        return permutation;
    }
    int tar = -1;
    for(int i = n-1;i>ind;i--)
    {
        if(permutation[ind] < permutation[i])
        {
            tar = i;
            break;
        }
    }
    
    swap(permutation[ind],permutation[tar]);
    int l = ind+1, r = n-1;
    while(l<r)
    {
        swap(permutation[l],permutation[r]);
        l++,r--;
    }
    return permutation;
}