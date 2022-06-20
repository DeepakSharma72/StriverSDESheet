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
    if(root->data == x)
    {
        ans.push_back(root->data);
        return true;
    }
    else if(getPath(root->left,x,ans))
    {
        ans.push_back(root->data);
        return true;
    }
    else if(getPath(root->right,x,ans))
    {
        ans.push_back(root->data);
        return true;
    }
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    bool flag = getPath(root,x,ans);
    if(flag)
    {
        reverse(ans.begin(),ans.end());
        return ans;
    }
    ans.push_back(-1);
    return ans;
}
