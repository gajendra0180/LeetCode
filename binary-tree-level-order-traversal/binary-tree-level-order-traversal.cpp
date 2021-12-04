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
    void traverse(TreeNode* r,map<int,vector<int>>&m,int level)
    {
        if(r==NULL)
            return;
        m[level].push_back(r->val);
        traverse(r->left,m,level+1);
        traverse(r->right,m,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int,vector<int>> m;
        vector<vector<int>> res;
        traverse(root,m,0);
        for(auto i:m)
            res.push_back(i.second);
        return res;
    }
};