/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<queue>
vector<int> getLeftView(TreeNode<int> *root)
{
    queue<TreeNode<int>*> q;
    vector<int> ans;
    if(root == NULL)
        return ans;
    q.push(root);
    while(!q.empty())
    {
        int sz = q.size();
        for(int i=0;i<sz;i++)
        {
            TreeNode<int>* node = q.front();
            q.pop();
            if(i == 0)
            {
                ans.push_back(node->data);
            }
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
    }
    return ans;
}