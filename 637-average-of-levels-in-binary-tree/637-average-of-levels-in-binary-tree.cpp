class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        deque<TreeNode*>dq;
        dq.push_back(root);
        vector<double>res;
        while(dq.size()){
            double n=dq.size(),s=0;
            for(int i=0;i<n;i++){
                auto fr=dq.front();
                dq.pop_front();
                s+=fr->val;
                if(fr->left)
                    dq.push_back(fr->left);
                if(fr->right)
                    dq.push_back(fr->right);
            }
            res.push_back((s/n));
        }
        return res;
    }
};