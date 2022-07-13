
class Solution {
public:
    int get(TreeNode* r){
        if(r==NULL)
            return 0;
        return 1+max(get(r->left),get(r->right));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        deque<pair<TreeNode*,int>>dq;
        dq.push_back({root,0});
        int h=get(root);
        vector<vector<int>>res;
        for(int i=0;i<h;i++){
            vector<int>temp;
            res.push_back(temp);
        }
        while(dq.size()){
            auto b=dq.front();
            auto a=b.first;
            int l=b.second;
            dq.pop_front();
            if(a->left)
                dq.push_back({a->left,l+1});
            if(a->right)
            dq.push_back({a->right,l+1});
            res[l].push_back(a->val);
        }
        
        return res;
    }
};