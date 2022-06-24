/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<stack>

void Lrightshift(stack<BinaryTreeNode<int>*> &S)
{
    BinaryTreeNode<int> *root = S.top();
    S.pop();
    if(root->right)
    {
        root = root->right;
        while(root)
        {
            S.push(root);
            root = root->left;
        }
    }
}

void Rleftshift(stack<BinaryTreeNode<int>*> &S)
{
    BinaryTreeNode<int>* root = S.top();
    S.pop();
    if(root->left)
    {
        root = root->left;
        while(root)
        {
            S.push(root);
            root = root->right;
        }
    }
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    stack<BinaryTreeNode<int>*> L,R;
    BinaryTreeNode<int> *cur = root;
    while(cur)
    {
        L.push(cur);
        cur = cur->left;
    }
    cur = root;
    while(cur)
    {
        R.push(cur);
        cur = cur->right;
    }
    while(!L.empty() && !R.empty() && L.top()->data < R.top()->data)
    {
         int sum = L.top()->data + R.top()->data;
         if(sum == k)
             return true;
        else if(sum > k)
        {
            Rleftshift(R);
        }
        else
        {
            Lrightshift(L);
        }
    }
    return false;
}


