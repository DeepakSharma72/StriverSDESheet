
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL)
        return;
        
        Node* lft = node->left;
        Node* rgt = node->right;
        node->left = rgt;
        node->right = lft;
        mirror(node->left);
        mirror(node->right);
    }
};