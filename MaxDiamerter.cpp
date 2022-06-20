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

**********************************************************/

struct Node{
    int H,CW;
    Node(int h,int cw)
    {
        H = h,CW = cw;
    }
};


Node* maxWidth(TreeNode<int> *root)
{
    if(root == NULL)
    {
        return new Node(0,0);
    }
    Node* L = maxWidth(root->left);
    Node* R = maxWidth(root->right);
    int mw = max(L->CW,max(R->CW,L->H + R->H + 1));
    int mh = max(L->H,R->H)  + 1;
    return new Node(mh,mw);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	Node* ans = maxWidth(root);
    return (ans->CW - 1);
}
