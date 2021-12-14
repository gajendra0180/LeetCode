class Solution {
public:
    int res=0;
    void traverse(TreeNode* r,int low,int high)
    {
        if(r==NULL)
            return;
        if(r->val>=low&&r->val<=high)
            res+=r->val;
        if(r->val>=low&&r->val<=high)
        {
            traverse(r->left,low,high);
            traverse(r->right,low,high);
        }
        else if(r->val<low)
            traverse(r->right,low,high);
        else if(r->val>high)
            traverse(r->left,low,high);

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        traverse(root,low,high);
        return res;
    }
};