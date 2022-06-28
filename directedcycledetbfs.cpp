#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  int ctr = 0;
  vector<vector<int>> G(n+1);
  vector<int> Indeg(n+1,0);
  for(auto it:edges)
  {
      G[it.first].push_back(it.second);
      Indeg[it.second]++;
  }
    queue<int> q;
  for(int i=1;i<=n;i++)
  {
      if(Indeg[i] == 0)
      {
          q.push(i);
      }
  }
    while(!q.empty())
    {
        ctr++;
        int node = q.front();
        q.pop();
        for(auto it:G[node])
        {
            Indeg[it]--;
            if(Indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return (ctr != n);
}