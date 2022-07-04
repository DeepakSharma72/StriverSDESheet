struct TrieNode{
  TrieNode* link[26];
  TrieNode()
  {
     for(int i=0;i<26;i++)
     {
         link[i] = NULL;
     }
  }
  bool isLinkExist(char ch)
  {
      return (link[ch-'a'] != NULL);
  }
  void makeLink(char ch)
  {
      link[ch-'a'] = new TrieNode();
  }
  TrieNode* getLink(char ch)
  {
      return link[ch-'a'];
  }
};

void dfs(TrieNode* root,int &ans)
{
    for(int i=0;i<26;i++)
    {
        if(root->isLinkExist(i + 'a'))
        {
            ans++;
            dfs(root->link[i],ans);
        }
    }
}

int distinctSubstring(string &word) {
    TrieNode* root = new TrieNode();
     for(int i=0;i<word.size();i++)
     {
         TrieNode* node = root;
         for(int j=i;j<word.size();j++)
         {
             if(node->isLinkExist(word[j]) == false)
             {
                 node->makeLink(word[j]);
             }
             node = node->getLink(word[j]);
         }
     }
    int ans = 0;
    dfs(root,ans);
    return ans;
}
