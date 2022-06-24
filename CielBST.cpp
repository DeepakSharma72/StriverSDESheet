/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void getAns(BinaryTreeNode<int> *node,int tar,int &ans)
{
    if(node == NULL)
        return;
    if(node->data == tar)
    {
        ans = tar;
        return; 
    }
    if(node->data < tar)
    {
        getAns(node->right,tar,ans);
    }
    else
    {
        ans = node->data;
        getAns(node->left,tar,ans);
    }
}

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = 1e9+1;
    getAns(node,x,ans);
    if(ans == 1e9+1)
        return -1;
    return ans;
}