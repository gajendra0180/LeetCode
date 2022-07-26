class Solution {
public:
    void get(TreeNode* r,TreeNode* f,vector<TreeNode*>&v,vector<TreeNode*>&ans){
        if(!r)return;
        if(r==f){
            v.push_back(r);
            ans=v;
            return;
        }
        v.push_back(r);
        get(r->left,f,v,ans);
        get(r->right,f,v,ans);
        v.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1,v2,ans1,ans2;
         get(root,p,v1,ans1);
         get(root,q,v2,ans2);
        int i=0;
        for(i=0;i<min(ans1.size(),ans2.size());i++)
            if(ans1[i]->val!=ans2[i]->val)
                return ans1[i-1];
        if(i==ans1.size())return ans1.back();
        if(i==ans2.size())return ans2.back();
        return NULL;
    }
};