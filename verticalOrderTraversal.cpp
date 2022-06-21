/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<queue>
#include<map>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    queue<pair<TreeNode<int>*,int>> q;
    if(root)
    {
        q.push({root,0});
    }
    map<int,vector<int>> mp;
    while(!q.empty())
    {
        TreeNode<int>* node = q.front().first;
        int idx = q.front().second;
        q.pop();
        mp[idx].push_back(node->data);
        if(node->left)
        {
            q.push({node->left,idx-1});
        }
        if(node->right)
        {
            q.push({node->right,idx+1});
        }
    }
    for(auto v:mp)
    {
        for(auto i:v.second)
        {
            ans.push_back(i);
        }
    }
    return ans;
}