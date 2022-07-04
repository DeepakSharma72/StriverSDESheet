#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *link[26];
    int preCount = 0;
    int strCount = 0;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            link[i] = NULL;
        }
        preCount = 0;
        strCount = 0;
    }
    bool isNextLinkExist(char ch)
    {
        return (link[ch - 'a'] != NULL);
    }
    void makeNextLink(char ch)
    {
        link[ch - 'a'] = new TrieNode();
    }
    TrieNode *getNextLink(char ch)
    {
        return link[ch - 'a'];
    }
    void INCpreCount()
    {
        preCount++;
    }
    void DECpreCount()
    {
        preCount--;
    }
    void makeEnd()
    {
        strCount++;
    }
    void eraseEnd()
    {
        strCount--;
    }
    int getPrefixes()
    {
        return preCount;
    }
    int getStrings()
    {
        return strCount;
    }
};

class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string &word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char it = word[i];
            if (node->isNextLinkExist(it) == false)
            {
                node->makeNextLink(it);
            }
            node = node->getNextLink(it);
            node->INCpreCount();
        }
        node->makeEnd();
    }
    int countWordsEqualTo(string &word)
    {
        TrieNode *node = root;
        for (auto it : word)
        {
            if (node->isNextLinkExist(it) == false)
            {
                return 0;
            }
            node = node->getNextLink(it);
        }
        return node->getStrings();
    }
    int countWordsStartingWith(string &word)
    {
        TrieNode *node = root;
        for (auto it : word)
        {
            if (node->isNextLinkExist(it) == false)
            {
                return 0;
            }
            node = node->getNextLink(it);
        }
        return node->getPrefixes();
    }
    void erase(string &word)
    {
        TrieNode *node = root;
        for (auto it : word)
        {
            node = node->getNextLink(it);
            node->DECpreCount();
        }
        node->eraseEnd();
    }
};