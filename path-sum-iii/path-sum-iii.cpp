
class Solution {
public:
    
    void solve(TreeNode* root,int targetSum,map<int,int> m,int &res,int currSum)
    {
        if(root==NULL)
            return;
        currSum+=root->val;
        
        int req=currSum-targetSum;
        
        if(m.find(req)!=m.end())
            res+=m[req];
        
        m[currSum]++;
        
        solve(root->left,targetSum,m,res,currSum);
        solve(root->right,targetSum,m,res,currSum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int res=0;
        map<int,int> m;
        m[0]=1;
        solve(root,targetSum,m,res,0);
        return res;
    }
};
