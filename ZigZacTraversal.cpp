/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    bool LtoR = true;
    vector<int> ans;
    if(root == NULL)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
        int sz = q.size();
        vector<int> temp;
        for(int i=0;i<sz;i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            temp.push_back(node->data);
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        for(int i=0;i<sz;i++)
        {
             if(LtoR)
             ans.push_back(temp[i]);
             else
             ans.push_back(temp[sz-1-i]);
         }
       LtoR = !LtoR;
    }
 return ans;   
}
