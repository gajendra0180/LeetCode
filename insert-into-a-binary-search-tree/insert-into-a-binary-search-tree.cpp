class Solution {
public:
    void traverse(TreeNode* r,vector<int>&v)
    {
        if(r==NULL)
            return;
        v.push_back(r->val);
        traverse(r->left,v);traverse(r->right,v);
    }
    TreeNode* make(int i,int j,vector<int>&v)
    {
        if(i>j)return NULL;
        int mid=(i+j)/2;
        TreeNode* temp=new TreeNode(v[mid]);
        temp->left=make(i,mid-1,v);
        temp->right=make(mid+1,j,v);
        return temp;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        vector<int> v;
        traverse(root,v);
        for(auto i:v)cout<<i;
        v.push_back(val);
        sort(v.begin(),v.end());
         TreeNode* res=make(0,v.size()-1,v);
        return res;
    }
};