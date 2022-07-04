class TrieNode{
  public:
  TrieNode* link[26];
  bool isEnd;
  TrieNode()
  {
      for(int i=0;i<26;i++)
      {
          link[i] = NULL;
      }
      isEnd = false;
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
  bool isStringEnd()
  {
      return isEnd;
  }
  void makeStringEnd()
  {
      isEnd = true;
  }
};
void dfs(TrieNode* root,string cans,string &ans,char ch)
{
    if(root->isStringEnd() == false)
    {
        return;
    }
    cans.push_back(ch);
    if(ans.size() < cans.size())
    {
       ans = cans;
    }
    TrieNode* node = root;
    for(int i=0;i<26;i++)
    {
        if(node->isLinkExist(i + 'a'))
        {
             dfs(node->link[i],cans,ans,i+'a');   
        }
    }
}

string completeString(int n, vector<string> &a){
    TrieNode* root = new TrieNode();
    for(auto str:a)
    {
        TrieNode* node = root;
        for(auto it:str)
        {
            if(node->isLinkExist(it) == false)
            {
                node->makeLink(it);
            }
            node = node->getLink(it);
        }
        node->makeStringEnd();
    }
    string cans = "";
    string ans = "";
    for(int i=0;i<26;i++)
    {
        if(root->isLinkExist(i + 'a'))
        {
            dfs(root->link[i],cans,ans,i+'a');
        }
    }
    
    return (ans == ""?"None":ans);
}