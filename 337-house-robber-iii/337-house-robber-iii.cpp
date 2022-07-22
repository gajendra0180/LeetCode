class Solution {
public:
    map<TreeNode*,int>m;
    int rob(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        if(m.find(root)!=m.end())
            return m[root];
        int a=0,b=0;
        if(root->left)
            a=rob(root->left->left)+rob(root->left->right);
        if(root->right)
            b=rob(root->right->left)+rob(root->right->right);
        int liya=root->val+a+b;
        int nhiLiya=rob(root->left)+rob(root->right);
        
        return m[root] = max(liya,nhiLiya);
        
    }
};