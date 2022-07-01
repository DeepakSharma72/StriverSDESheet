#include<queue>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<int> distance(vertices,2147483647);
    distance[source] = 0;
    vector<vector<pair<int,int>>> G(vertices);
    for(auto it:vec)
    {
        G[it[0]].push_back({it[1],it[2]});
        G[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    while(pq.size())
    {
        int curwgt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:G[node])
        {
            if(it.second + curwgt < distance[it.first])
            {
                pq.push({curwgt + it.second,it.first});
                distance[it.first] = curwgt + it.second;
            }
        }
    }
    return distance;
}
