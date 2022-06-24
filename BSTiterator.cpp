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
#include<stack>
class BSTiterator
{
    stack<TreeNode<int>*> s;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
    }

    int next()
    {
        int val = s.top()->data;
        TreeNode<int>* cur = s.top();
        s.pop();
        cur = cur->right;
        while(cur)
        {
            s.push(cur);
            cur = cur->left;
        }
        return val;
    }

    bool hasNext()
    {
        return s.size();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/