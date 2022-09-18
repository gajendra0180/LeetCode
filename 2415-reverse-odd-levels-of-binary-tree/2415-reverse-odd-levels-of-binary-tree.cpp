class Solution {
public:
    map<int,vector<TreeNode*>>m;
    void t(TreeNode* &r,int d){
        if(!r)
            return;
        m[d].push_back(r);
        t(r->left,d+1);
        t(r->right,d+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        t(root,0);
        for(auto &i:m){
            if(i.first%2!=0)
            {
                for(int k=0;k<i.second.size()/2;k++){
                    swap(i.second[k]->val,i.second[i.second.size()-k-1]->val);
                }
            }
        }
        return root;
    }
};