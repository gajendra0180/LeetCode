
class Solution {
public:
    void hasBoth(TreeNode* r,TreeNode* p,TreeNode *q,int &c,int &d){
        if(r==NULL)
            return;
        if(r==p)
            c=1;
        if(r==q)
            d=1;
        hasBoth(r->left,p,q,c,d);
        hasBoth(r->right,p,q,c,d);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int c1=0,c2=0,c3=0,c4=0;
        hasBoth(root->left,p,q,c1,c2);
         hasBoth(root->right,p,q,c3,c4);
        if(c1&&c2){
            return lowestCommonAncestor(root->left,p,q);
        }else if(c3&&c4){
            return lowestCommonAncestor(root->right,p,q);
        }
        else
            return root;
    }
};