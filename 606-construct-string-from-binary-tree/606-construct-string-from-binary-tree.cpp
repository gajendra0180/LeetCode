class Solution {
public:
    string res;
    void t(TreeNode * r){
        if(!r)return;
        res.push_back('(');
        res=res+to_string(r->val);
        if(r->left ==NULL && r->right == NULL){
                res.push_back(')');
                return;
        };
        if(r->left && r->right == NULL){
            t(r->left);
        }
        else if(r->left == NULL && r->right){
            res=res+"()";
            t(r->right);
        }else {
            t(r->left);
            t(r->right);
        }
        res.push_back(')');
    }
    string tree2str(TreeNode* root) {
         t(root);
        return res.substr(1,res.size()-2);
    }
};