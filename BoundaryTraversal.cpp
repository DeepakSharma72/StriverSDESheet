/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root)
{
    return (root->left == NULL && root->right == NULL);
}

void LeftBoundary(TreeNode<int>* root,vector<int> &ans)
{
    if(root == NULL || isLeaf(root))
        return;
    ans.push_back(root->data);
    if(root->left)
    {
        LeftBoundary(root->left,ans);
    }
    else
    {
        LeftBoundary(root->right,ans);
    }
}

void RightBoundary(TreeNode<int>* root,vector<int> &ans)
{
    if(root == NULL || isLeaf(root))
        return;
    if(root->right)
    {
        RightBoundary(root->right,ans);
    }
    else
    {
        RightBoundary(root->left,ans);
    }
    ans.push_back(root->data);
}

void Leafes(TreeNode<int> *root,vector<int> &ans)
{
    if(root == NULL)
        return;
    if(isLeaf(root))
    {
        ans.push_back(root->data);
    }
    if(root->left)
    {
        Leafes(root->left,ans);
    }
    if(root->right)
    {
        Leafes(root->right,ans);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
   vector<int> ans;
    if(root == NULL)
        return ans;
    if(!isLeaf(root))
    {
        ans.push_back(root->data);
    }
    LeftBoundary(root->left,ans);
    Leafes(root,ans);
    RightBoundary(root->right,ans);
    return ans;
}