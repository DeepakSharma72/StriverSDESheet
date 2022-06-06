#include <bits/stdc++.h> 
#include <vector>
using namespace std;

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int C = mat[0].size();
    for(int i=0;i<mat.size();i++)
    {
        if(target < mat[i][0] || target > mat[i][C-1])
        {
            continue;
        }
        int lo = 0,hg = C-1;
        while(lo <= hg)
        {
            int mid = (lo + hg)/2;
            if(mat[i][mid] == target)
                return true;
            else if(mat[i][mid] > target)
            {
                hg = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }
    }
    return false;
}