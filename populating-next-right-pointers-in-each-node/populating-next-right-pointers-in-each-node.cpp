class Solution {
public:
    void link(Node* left,Node*right)
    {
        if(left==NULL&&right==NULL)
            return;
        
        left->next=right;
        
        link(left->left,left->right);
        link(left->right,right->left);
        link(right->left,right->right);

    }
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        
        link(root->left,root->right);
        return root;
        
    }
};