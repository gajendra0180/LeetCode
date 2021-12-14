class Solution {
public:
    int res=0;
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return 0;
        
        dfs(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);

        return res;
    }
    void dfs(TreeNode* root,int sum)
    {
        if(root==NULL)
            return;
        
        if(sum==root->val)
            res++;
        
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);

    }
};