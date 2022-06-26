#include <queue>
#include <utility>
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int color)
{
    int tar = image[x][y];
    queue<pair<int, int>> q;
    q.push({x, y});
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (image[r][c] == color)
        {
            continue;
        }
        image[r][c] = color;
        // cout<<r<<" - "<<c<<endl;
        for (int i = 0; i < 4; i++)
        {
            int _r = r + dx[i];
            int _c = c + dy[i];
            if (_r < 0 || _r >= image.size() || _c < 0 || _c >= image[0].size() || image[_r][_c] != tar)
            {
                continue;
            }
            q.push({_r, _c});
        }
    }
    return image;
}