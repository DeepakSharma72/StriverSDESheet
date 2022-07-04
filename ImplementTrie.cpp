/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct TrieNode{
    TrieNode* list[26];
    bool isEnd;
    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            list[i] = NULL;
        }
        isEnd = false;
    }
    bool isNextLinkExist(char ch)
    {
        return (list[ch-'a'] != NULL);
    }
    void makeNextLink(char ch)
    {
        list[ch-'a'] = new TrieNode();
    }
    TrieNode* getNextLink(char ch)
    {
        return list[ch-'a'];
    }
    void makeNodeEnd()
    {
        isEnd = true;
    }
    bool isNodeEnd()
    {
        return isEnd;
    }
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for(auto it:word)
        {
            if(node->isNextLinkExist(it) == false)
            {
                node->makeNextLink(it);
            }
            node = node->getNextLink(it);
        }
        node->makeNodeEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(auto it:word)
        {
            if(node->isNextLinkExist(it) == false)
            {
                return false;
            }
            node = node->getNextLink(it);
        }
        return node->isNodeEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto it:prefix)
        {
            if(node->isNextLinkExist(it) == false)
            {
                return false;
            }
            node = node->getNextLink(it);
        }
        return true;
    }
};