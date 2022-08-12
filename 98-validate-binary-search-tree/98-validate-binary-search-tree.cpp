class Solution {
public:
    bool Maxx(TreeNode* root){
        int vall=root->val;
        root=root->left;
        if(!root)return true;
        while(root->right)root=root->right;
        return root->val<vall;
    }
    bool Minn(TreeNode* root){
        int vall=root->val;
        root=root->right;
        if(!root)return true;
        while(root->left)root=root->left;
        return root->val>vall;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        if(root->left==NULL && root->right == NULL)
            return true;
        bool isLeftBST= isValidBST(root->left);
        bool isRightBST= isValidBST(root->right);
        if(isLeftBST && isRightBST && Maxx(root) && Minn(root))
            return true;
        return false;
    }
};