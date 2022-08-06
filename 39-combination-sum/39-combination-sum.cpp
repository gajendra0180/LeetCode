class Solution {
public:
    vector<vector<int>>res;
    void get(vector<int>&v,int t,int i,int sum,vector<int>tres){
        
        if(i>=v.size())
            return;
        
        if(sum+v[i]==t){
            tres.push_back(v[i]);
            res.push_back(tres);
            return;
        }
        
        if(sum+v[i]<t){
            get(v,t,i+1,sum,tres);
            tres.push_back(v[i]);
            sum+=v[i];
            get(v,t,i,sum,tres);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        get(v,target,0,0,{});
        return res;
    }
};