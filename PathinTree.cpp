/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool getPath(TreeNode<int> *root,int x,vector<int> &ans)
{
    if(root == NULL)
        return false;
    ans.push_back(root->data);
    if(root->data == x)
    {
        return true;
    }
    if(getPath(root->left,x,ans))
    {
        return true;
    }
    if(getPath(root->right,x,ans))
    {
        return true;
    }
    ans.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    bool flag = getPath(root,x,ans);
    if(flag)
    {
        return ans;
    }
    ans.push_back(-1);
    return ans;
}
