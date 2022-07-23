
class Solution {
public:
    int calc(TreeNode*r,int minn,int maxx){
        if(r==NULL)
            return maxx-minn;
        
        maxx=max(r->val,maxx);
        minn=min(r->val,minn);
        
        int lefT=calc(r->left,minn,maxx);
        int righT=calc(r->right,minn,maxx);
        return max(lefT,righT);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        return calc(root,INT_MAX,INT_MIN);
    }
};