#include <bits/stdc++.h> 
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	for(int i=0;i<n;i++)
    {
        int ind = abs(arr[i]);
        if(arr[ind] < 0)
        {
            return ind;
        }
        arr[ind] *= -1;
    }
    return -1;
}
