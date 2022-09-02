
class Solution {
public:
    int res=0;
    void traverse(TreeNode* r,map<int,int>&m){
        if(!r)
            return;
        if(m.size()==0)
            res++;
        else if(m.rbegin()->first<=r->val)
            res++;
        m[r->val]++;    
        traverse(r->left,m);
        traverse(r->right,m);
        m[r->val]--;
        
        if(m[r->val]==0)   
            m.erase(r->val);
    }
    int goodNodes(TreeNode* root) {
        map<int,int> m;
        traverse(root,m);
        return res;
    }
};