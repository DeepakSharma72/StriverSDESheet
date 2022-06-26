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

string serializeTree(TreeNode<int> *root)
{
    string ans = "";
    queue<TreeNode<int>*> q;
    if(root == NULL)
    {
        return "null,";
    }
    else
    {
        ans += to_string(root->data);
        ans.push_back(',');
        q.push(root);
    }
    while(!q.empty())
    {
        TreeNode<int>* node = q.front();
        q.pop();
        if(node->left)
        {
            ans += to_string(node->left->data);
            ans.push_back(',');
            q.push(node->left);
        }
        else
        {
            ans += "null,";
        }
        if(node->right)
        {
            ans += to_string(node->right->data);
            ans.push_back(',');
            q.push(node->right);
        }
        else
        {
            ans += "null,";
        }
    }
    return ans;
}

TreeNode<int>* deserializeTree(string &str)
{
     queue<TreeNode<int>*> q;
     int i = 0;
     string temp = "";
     while(str[i] != ',')
     {
         temp.push_back(str[i++]);
     }
     i++;
     TreeNode<int>* root = NULL;
     if(temp == "null")
     {
        return NULL;         
     }
     else
     {
         root = new TreeNode<int>(stoi(temp));
         q.push(root);
     }
     while(i<str.size())
     {
         TreeNode<int>* node = q.front();
         q.pop();
         temp = "";
         while(str[i] != ',')
         {
             temp.push_back(str[i++]);
         }
         i++;
         if(temp == "null")
         {
            node->left = NULL;         
         }
         else
         {
             node->left = new TreeNode<int>(stoi(temp));
             q.push(node->left);
         }
         temp = "";
         while(str[i] != ',')
         {
             temp.push_back(str[i++]);
         }
         i++;
         if(temp == "null")
         {
            node->right = NULL;         
         }
         else
         {
             node->right = new TreeNode<int>(stoi(temp));
             q.push(node->right);
         }
     }
    return root;
}



