class Solution {
public:
    void traverse(TreeNode* r,int depth,int reqDepth,int val){
        if(!r)
            return;
        if(depth==reqDepth-1){
            TreeNode* temp=r->left;
            r->left=new TreeNode(val);
            r->left->left=temp;
            temp=r->right;
            r->right=new TreeNode(val);
            r->right->right=temp;
        }
        traverse(r->left,depth+1,reqDepth,val);
        traverse(r->right,depth+1,reqDepth,val);

    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        else
        {
            traverse(root,1,depth,val);
            return root;
        }
    }
};