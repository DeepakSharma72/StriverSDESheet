/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<queue>
#include<map>
vector<int> getTopView(TreeNode<int> *root) {
        vector<int> res;
    map<int,int> mp;
    if(root == NULL)
        return res;
    
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    mp[0] = root->val;
    while(!q.empty())
    {
        int key = q.front().second;
        TreeNode<int>* node = q.front().first;
        q.pop();
        
        if(mp.find(key) == mp.end())
        mp[key] = node->val;;
        
        if(node->left)
        {
            q.push({node->left,key-1});
        }
        if(node->right)
        {
            q.push({node->right,key+1});
        }
    }
    for(auto it:mp)
    {
        res.push_back(it.second);
    }
    return res;
}