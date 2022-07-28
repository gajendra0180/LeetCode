class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL || root->left==NULL&&root->right==NULL)
            return;
        
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp=root->left;
        if(temp){
            while(temp->right!=NULL)
                temp=temp->right;
            TreeNode* temp1=root->right;
            TreeNode* t=root->left;
            root->left=NULL;
            root->right=NULL;
            root->right=t;
            temp->right=temp1;
        }
    }
};