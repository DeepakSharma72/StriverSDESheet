#include<bits/stdc++.h>
using namespace std;
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

int getMaxXor(TrieNode *root, int num)
{
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        bool bit = (num & (1 << i));
        if(bit)
        {
            cout<<i<<" ";
        }
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
    cout<<ans<<endl;
    return ans;
}

int maximumXor(vector<int> A)
{
    TrieNode *root = new TrieNode();
    for (auto it : A)
    {
        TrieNode *node = root;
        for (int i = 30; i >= 0; i--)
        {
            bool bit = (it & (1 << i));
            if (node->isLinkExist(bit) == false)
            {
                node->makeLink(bit);
            }
            node = node->getLink(bit);
        }
    }
    cout<<"Insertion done\n";
    int ans = -1;
    for (auto it : A)
    {
        ans = max(ans, getMaxXor(root, it));
    }
    return ans;
}

int main()
{
    vector<int> v = {2,1,4};
    cout<<maximumXor(v)<<endl;
}