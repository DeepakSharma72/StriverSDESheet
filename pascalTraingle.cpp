#include <bits/stdc++.h> 
using namespace std;
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> triangle;
    triangle.push_back({1});
    for(int i=2;i<=n;i++)
    {
        vector<long long int> v;
        for(int j=1;j<=i;j++)
        {
            if(j == 1)
            {
                v.push_back(triangle[i-2][j-1]);
            }
            else if(j == i)
            {
                v.push_back(triangle[i-2][j-2]);
            }
            else
            {
                v.push_back(triangle[i-2][j-1] + triangle[i-2][j-2]);
            }
        }
        triangle.push_back(v);
    }
    return triangle;
}
