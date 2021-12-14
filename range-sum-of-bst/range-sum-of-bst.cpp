/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res=0;
    void traverse(TreeNode* r,int low,int high)
    {
        if(r==NULL)
            return;
        if(r->val>=low&&r->val<=high)
            res+=r->val;
        traverse(r->left,low,high);
        traverse(r->right,low,high);

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        traverse(root,low,high);
        return res;
    }
};