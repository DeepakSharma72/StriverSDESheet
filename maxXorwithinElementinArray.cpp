#include <bits/stdc++.h>

struct TrieNode
{
    TrieNode *bits[2];
    TrieNode()
    {
        bits[0] = bits[1] = NULL;
    }
    bool isLinkExist(int bit)
    {
        return (bits[bit] != NULL);
    }
    void makeLink(int bit)
    {
        bits[bit] = new TrieNode();
    }
    TrieNode *getLink(int bit)
    {
        return bits[bit];
    }
};

struct node
{
    int x, a, idx;
    node(int _x, int _a, int _i)
    {
        x = _x, a = _a, idx = _i;
    }
};

int getMaxXor(TrieNode *root, int num)
{
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        bool bit = (num & (1 << i));
        if (root->isLinkExist(1 - bit))
        {
            ans = (ans | (1 << i));
            root = root->getLink(1 - bit);
        }
        else
        {
            root = root->getLink(bit);
        }
    }
    return ans;
}

void Insertion(TrieNode *&root, int num)
{
    TrieNode *node = root;
    for (int i = 30; i >= 0; i--)
    {
        bool bit = (num & (1 << i));
        if (node->isLinkExist(bit) == false)
        {
            node->makeLink(bit);
        }
        node = node->getLink(bit);
    }
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    sort(arr.begin(), arr.end());
    vector<node> Q;
    for (int i = 0; i < queries.size(); i++)
    {
        Q.push_back(node(queries[i][0], queries[i][1], i));
    }
    sort(Q.begin(), Q.end(), [&](node aq, node bq)
         { return aq.a < bq.a; });
    vector<int> ans(queries.size(), -1);
    int i = 0;
    TrieNode *root = new TrieNode();
    for (auto it : Q)
    {
        int val = it.a;
        int num = it.x;
        int idx = it.idx;
        if(val < arr[0])
        {
            continue;
        }
        while (i < arr.size() && val >= arr[i])
        {
            Insertion(root, arr[i]);
            i++;
        }
        ans[idx] = getMaxXor(root, num);
    }
    return ans;
}
