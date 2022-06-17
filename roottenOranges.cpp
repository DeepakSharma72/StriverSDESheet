#include<queue>
struct node{
    int r,c,time;
    node(int rr,int cc,int tt)
    {
        r = rr,c = cc,time = tt;
    }
};

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int ans = 0;
    int R = grid.size(),C = grid[0].size();
    queue<node> q;
    int oranges = 0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(grid[i][j] == 2)
            {
                q.push(node(i,j,0));
            }
            else if(grid[i][j] == 1)
            {
                oranges++;
            }
        }
    }
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    int ctr = 0;
    while(!q.empty())
    {
        int r = q.front().r;
        int c = q.front().c;
        int time = q.front().time;
        ans = max(ans,time);
        q.pop();
        for(int i=0;i<4;i++)
        {
            int _r = r + dx[i];
            int _c = c + dy[i];
            if(_r < 0 || _c < 0 || _r >= R || _c >= C || grid[_r][_c] != 1)
            {
                continue;
            }
            grid[_r][_c] = 2;
            q.push(node(_r,_c,time+1));
            ctr++;
        }
    }
    if(ctr != oranges)
        return -1;
    return ans;
}