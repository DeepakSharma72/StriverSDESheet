#include<queue>
struct Node{
    int left,right,level;
    Node(int l,int r,int lv)
    {
        left = l,right = r,level = lv;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    vector<int> pos(N+1,0);
    for(int i=0;i<N;i++)
    {
        pos[inorder[i]] = i;
    }
    queue<Node*> q;
   
    q.push(new Node(0,N-1,0));
    int ans = 0;
    int idx = 0;
    while(!q.empty())
    {
        Node* ptr = q.front();
        q.pop();
        if(ptr->left > ptr->right || idx >= N)
            continue;
        ans = max(ans,ptr->level);
        int index = pos[levelOrder[idx++]];
        
        q.push(new Node(ptr->left,index-1,ptr->level+1));
        q.push(new Node(index+1,ptr->right,ptr->level+1));
    }
    return ans;
}