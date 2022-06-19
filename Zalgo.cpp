int zAlgorithm(string s, string p, int n, int m)
{
    string str = p + "#" + s;
    int tarlen = p.size();
    int ans = 0;
    vector<int> Z(n + m + 1, 0);
    int l = 0, r = 0;
    for (int i = 1; i < (n + m + 1); i++)
    {
        if (i <= r)
        {
            Z[i] = min(Z[i - l], r - i + 1);
        }
        while (i + Z[i] < str.size() && str[Z[i]] == str[i + Z[i]])
        {
            Z[i]++;
        }
        if (Z[i] == m)
            ans++;
        if (i + Z[i] - 1 > r)
        {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return ans;
}