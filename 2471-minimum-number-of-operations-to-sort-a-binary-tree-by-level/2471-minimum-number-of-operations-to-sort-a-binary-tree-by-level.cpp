class Solution {
public:
    int get(vector<int>v)
{
 vector<int>sortedVector;
        sortedVector=v;
        sort(sortedVector.begin(),sortedVector.end());
        map<int,int> m;
        for (int i = 0; i < v.size(); i++) m[v[i]]=i;
        int index = 0, res = 0;
        for(auto ele:sortedVector){
            int eleKidharHai=m[ele];
            if (eleKidharHai != index) res++;
            int temp = v[index];
            v[index] = ele;
            v[eleKidharHai] = temp;
            m[ele]=index;
            m[temp]=eleKidharHai;
            index++;
        }
        return res;
        
}
    map<int,vector<int>>tr;
    void traverse(TreeNode* r,int level){
        if(!r)return;
        tr[level].push_back(r->val);
        traverse(r->left,level+1);
        traverse(r->right,level+1);
    }
    int minimumOperations(TreeNode* root) {
        traverse(root,0);
        int res=0;
        for(auto i:tr){
            vector<int>v=i.second;
            // cout<<get(v)<<endl;
            res+=get(v);
        }
        return res;
        
    }
};