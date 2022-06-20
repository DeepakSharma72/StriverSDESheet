/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<vector>
vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> res;
    map<int,int> mp;
    if(root == NULL)
        return res;
    
    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,0});
    mp[0] = root->data;
    while(!q.empty())
    {
        int key = q.front().second;
        BinaryTreeNode<int>* node = q.front().first;
        q.pop();
        mp[key] = node->data;
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
