#include<queue>
int getTotalIslands(int** arr, int n, int m)
{
   int ans = 0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(arr[i][j] == 1)
           {
               ans++;
               queue<vector<int>> q;
//                cout<<i<<" "<<j<<endl;
               q.push({i,j});
               int dx[] = {-1,-1,-1,0,1,1,1,0};
               int dy[] = {-1,0,1,1,1,0,-1,-1};
               arr[i][j] = -1;
               while(!q.empty())
               {
                   int r = q.front()[0];
                   int c = q.front()[1];
                   q.pop();
                   for(int k=0;k<8;k++)
                   {
                       int _r = r + dx[k];
                       int _c = c + dy[k];
                       if(_r < 0 || _c < 0 || _r >= n || _c >= m || arr[_r][_c] != 1)
                           continue;
                           q.push({_r,_c});
                           arr[_r][_c] = -1;
                   }
               }
           }
       }
   }
    return ans;
}
