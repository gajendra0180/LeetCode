class Solution {
public:
    int getSum(TreeNode* r){
        if(!r)
            return 0;
        int leftSum=getSum(r->left);
        int rightSum=getSum(r->right);
        return r->val+leftSum+rightSum;        
    }
    int getNum(TreeNode* r){
        if(!r)return 0;
        int a=getNum(r->left);
        int b=getNum(r->right);
        return 1+a+b;
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root)return 0;
        int a=averageOfSubtree(root->left);
        int b=averageOfSubtree(root->right);
        if(getSum(root)/getNum(root)==root->val)
            return 1+a+b;
        else
            return a+b;
    }
};