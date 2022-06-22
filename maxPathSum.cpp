/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
struct node{
    long long maxsum;
    long long ssf;
    node(long long mxsum,long long ss)
    {
        maxsum = mxsum;
        ssf = ss;
    }
};


node getPathSum(TreeNode<int>* root,int &leaf)
{
        if(root->left == NULL && root->right == NULL)
        {
            leaf++;
            return node(root->val,root->val);
        }
        if(root->left == NULL)
        {
            long long rootval = root->val;
            node R = getPathSum(root->right,leaf);
            long long height = max(rootval,root->val + R.ssf);
            long long sum = max(height,R.maxsum);
            return node(sum,height);
        }
        if(root->right == NULL)
        {
            long long rootval = root->val;
            node L = getPathSum(root->left,leaf);
            long long height = max(rootval,root->val+L.ssf);
            long long sum = max(height,L.maxsum);
            return node(sum,height);
        }
       long long rootval = root->val;
        node R = getPathSum(root->right,leaf);
        node L = getPathSum(root->left,leaf);
        long long sum = max(R.maxsum,L.maxsum);
        long long val1 = max(R.ssf + L.ssf + root->val,max(R.ssf + root->val,L.ssf + root->val));
        val1 = max(val1,rootval);
        sum = max(sum,val1);
        
        long long hg = max(L.ssf + root->val,max(R.ssf + root->val,rootval));
        return node(sum,hg);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    if(root == NULL)
        return -1;
   int leaf = 0;
   node ans = getPathSum(root,leaf);
    if(leaf < 2)
        return -1;
   return ans.maxsum;
}