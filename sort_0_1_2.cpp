#include <bits/stdc++.h> 
using namespace std;
void sort012(int *arr, int n)
{
   int z_ctr = 0, o_ctr = 0,tw_ctr = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
            z_ctr++;
        else if(arr[i] == 1)
            o_ctr++;
        else
            tw_ctr++;
    }
    int i = 0;
    while(z_ctr)
    {
        arr[i] = 0;
        i++; 
        z_ctr--;
    }
    while(o_ctr)
    {
        arr[i] = 1;
        i++;
        o_ctr--;
    }
    while(tw_ctr)
    {
        arr[i] = 2;
        i++;
        tw_ctr--;
    }
}