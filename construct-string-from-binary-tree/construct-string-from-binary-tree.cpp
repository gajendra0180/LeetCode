class Solution {
public:
    void t(TreeNode* r,string &res)
    {
        if(!r)
            return;

        stringstream ss;
        ss<<r->val;
        string num;ss>>num;
        
        res+=num;
        
        if(!(r->left==NULL&&r->right==NULL))
        res.push_back('(');
        
        t(r->left,res);  
        
        if(!(r->left==NULL&&r->right==NULL))
        res.push_back(')');
        
        if((r->left==NULL&&r->right==NULL)||(r->left!=NULL&&r->right==NULL))
        {
            
        }
        else
        res.push_back('(');

        t(r->right,res); 
        if((r->left==NULL&&r->right==NULL)||(r->left!=NULL&&r->right==NULL))
        {
            
        }
        else
        res.push_back(')');
        
    }
    
    string tree2str(TreeNode* root) {
        string res;
        t(root,res);
        return res;
        
    }
};