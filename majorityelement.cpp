#include <bits/stdc++.h> 
using namespace std;

int findMajorityElement(int arr[], int n) {
	int ele = arr[0],ctr = 0;
    for(int i=1;i<n;i++)
    {
        if(ele == arr[i])
        {
            ctr++;
        }
        else
        {
            if(ctr > 0)
            {
                ctr--;
            }
            else
            {
                ele = arr[i];
                ctr = 0;
            }
        }
    }
    
    ctr = 0;
    for(int i=0;i<n;i++)
    {
        if(ele == arr[i])
        {
            ctr++;
        }
    }
    return (ctr > n/2)?ele:-1;
}