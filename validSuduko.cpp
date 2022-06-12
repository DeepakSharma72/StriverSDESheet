#include<bits/stdc++.h>
bool isValid(int matrix[9][9],int r,int c,int val)
{
    for(int j=0;j<9;j++)
    {
        if(matrix[r][j] == val)
            return false;
        if(matrix[j][c] == val)
            return false;
    }
    int _r = r - r%3;
    int _c = c - c%3; 
    int i = 0;
    int j = 0;
    while(i < 3)
    {
        while(j < 3)
        {
            if(matrix[_r + i][_c + j] == val)
                return false;
            j++;
        }
        i++;
    }
    return true;
}


bool isSudukoValid(int matrix[9][9],int r,int c)
{
    if(r == 9)
      return true;
    
    if(matrix[r][c] != 0)
    {
        if(c == 8)
            return isSudukoValid(matrix,r+1,0);
        else
            return isSudukoValid(matrix,r,c+1); 
    }
    else
    {
        for(int po = 1;po < 10;po++)
        {
            if(isValid(matrix,r,c,po))
            {
                matrix[r][c] = po;
                if((c == 8 && isSudukoValid(matrix,r+1,0)) || (c < 8 && isSudukoValid(matrix,r,c+1)))
                    return true;
                matrix[r][c] = 0;
            }
        }
    }
    return false;
}

bool isItSudoku(int matrix[9][9]) {
    return isSudukoValid(matrix,0,0);
}
