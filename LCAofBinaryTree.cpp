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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	if(root == NULL)
        return -1;
    if(root->data == x || root->data == y)
    {
        return root->data;
    }
    int L = lowestCommonAncestor(root->left,x,y);
    int R = lowestCommonAncestor(root->right,x,y);
    if(L != -1 && R != -1)
    {
        return root->data;
    }
    else if(L != -1 && R == -1)
    {
        return L;
    }
    else if(L == -1 && R != -1)
    {
        return R;
    }
    return -1;
}