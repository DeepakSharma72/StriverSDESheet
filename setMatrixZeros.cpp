#include <bits/stdc++.h> 
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
    int R = matrix.size(), C = matrix[0].size();
    bool rowcheck = false;
    bool colcheck = false;
    for(int i=0;i<R;i++)
    {
        if(matrix[i][0] == 0)
            rowcheck = true;
    }
    for(int j=0;j<C;j++)
    {
        if(matrix[0][j] == 0)
            colcheck = true;
    }
    for(int i=1;i<R;i++)
    {
        for(int j=1;j<C;j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for(int i=1;i<R;i++)
    {
        for(int j=1;j<C;j++)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if(rowcheck)
    {
        for(int i=0;i<R;i++)
        {
            matrix[i][0] = 0;
        } 
    }
    if(colcheck)
    {
        for(int j=0;j<C;j++)
        {
            matrix[0][j] = 0;
        }
    }
}