class Solution {
public:
    void traverse(TreeNode* r,TreeNode* &prev,bool &ans)
    {
        if(r==NULL)
            return;
        traverse(r->left,prev,ans);
        if(prev!=NULL&&r->val<=prev->val)
            ans=false;
        prev=r;
        cout<<r->val<<" "<<prev->val<<endl;
        traverse(r->right,prev,ans);
    }
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        TreeNode* prev=NULL;
        traverse(root,prev,ans);
        return ans;
    }
};
