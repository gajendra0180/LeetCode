
class Solution {
public:
    map<int,vector<int>> m;
    void bfs(TreeNode * r,int level){
        if(!r)
            return;
        m[level].push_back(r->val);
        bfs(r->left,level+1);
        bfs(r->right,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        bfs(root,0);
        vector<int>res;
        for(auto j:m){
            vector<int>temp = j.second;
            res.push_back(temp.back());
        }
        return res;
    }
};