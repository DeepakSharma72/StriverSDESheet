void getPandS(BinaryTreeNode<int>* root,int &prev,int &pred,int &suc,int key)
{
    if(root == NULL)
        return;
    if(pred != -1 && suc != -1)
        return;
    
    getPandS(root->left,prev,pred,suc,key);
    if(root->data == key)
    {
        pred = prev;
    }
    if(prev == key)
    {
        suc = root->data;
    }
    prev = root->data;
    getPandS(root->right,prev,pred,suc,key);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int prev = -1;
    int pred = -1,suc = -1;
    getPandS(root,prev,pred,suc,key);
    return {pred,suc};
}
