class Solution {
public:
    int fleve=0,res=0;
    void t(TreeNode* r, int level){
        
        if(r==NULL)
            return;
        
        fleve=max(fleve,level);   
        
        t(r->left,level+1);
        t(r->right,level+1);
    
    }
    
    void traverse(TreeNode* r, int level){
    
        if(r==NULL)
            return;
        
        if(level==fleve)
            res=res+r->val;
        
        traverse(r->left,level+1);
        traverse(r->right,level+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        t(root,0);
        traverse(root,0);
        return res;
    }
};