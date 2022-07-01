int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<long long> distance(n+1,1e9);
    distance[src] = 0;
    for(int round = 1;round < n;round++)
    {
        for(auto it:edges)
        {
       if(distance[it[0]] != 1e9 && distance[it[0]] + it[2] < distance[it[1]])
            {
                distance[it[1]] = distance[it[0]] + it[2];
            }
        }
    }
    return distance[dest];
}