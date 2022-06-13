
void RateinMaze(vector<vector<int>> &Maze,int n,int r,int c,vector<int> &v,vector<vector<int>> &res)
{
//     cout<<r<<" - "<<c<<endl;
     if(r == n-1 && c == n-1)
     {
         res.push_back(v);
         return;
     }
     int dx[] = {-1,0,1,0};
     int dy[] = {0,-1,0,1};
     for(int i=0;i<4;i++)
     {
         int _r = r + dx[i], _c = c + dy[i];
         if(_r >= n || _c >= n || _r < 0 || _c < 0 || Maze[_r][_c] == 0)
             continue;
         Maze[_r][_c] = 0;
         int ind = (_r*n + _c); 
         v[ind] = 1;
         RateinMaze(Maze,n,_r,_c,v,res);
         Maze[_r][_c] = 1;
         v[ind] = 0;
     }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> res;
    if(maze[0][0] == 0 || maze[n-1][n-1] == 0)
        return res;
    vector<int> v(n*n,0);
    v[0] = 1;
    maze[0][0] = 0;
    RateinMaze(maze,n,0,0,v,res);
    return res;
}