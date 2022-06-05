#include <bits/stdc++.h> 
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
       for(int round = 1;round <= min(n,m)/2;round++)
    {
        // uper row
        int i = round-1,j = round-1;
        int temp = mat[i][j];
        for(int k = j+1;k <= (m-round);k++)
        {
            int val = mat[i][k];
            mat[i][k] = temp;
            temp = val;
        }
        // right col
        i = round-1, j = m - round;
        for(int k = i+1;k<=(n-round);k++)
        {
            int val = mat[k][j];
            mat[k][j] = temp;
            temp = val;
        }
        // lower row
        i = n - round, j = m - round;
        for(int k = j - 1;k>=round-1;k--)
        {
            int val = mat[i][k];
            mat[i][k] = temp;
            temp = val;
        }
        // left col
        i = n - round, j = round-1;
        for(int k = i-1;k>=round-1;k--)
        {
            int val = mat[k][j];
            mat[k][j] = temp;
            temp = val;
        }
    }
}