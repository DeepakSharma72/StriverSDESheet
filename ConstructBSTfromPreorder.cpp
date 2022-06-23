/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* BuildBST(vector<int> &v,int &idx,int up)
{
    if(idx >= v.size() || v[idx] > up)
        return NULL;
    TreeNode<int>* node = new TreeNode<int>(v[idx++]);
    node->left = BuildBST(v,idx,node->data);
    node->right = BuildBST(v,idx,up);
    return node;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int idx = 0;
    TreeNode<int>* ans = BuildBST(preOrder,idx,1e9+7);
    return ans;
}