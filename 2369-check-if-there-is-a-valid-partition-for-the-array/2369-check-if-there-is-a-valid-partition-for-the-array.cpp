class Solution {
public:
    int dp[100001];
    bool get(vector<int>&v,int index){
        
        if(index==v.size())return true;
        
        if(dp[index]!=-1)
            return dp[index];
        
        bool ans=false;
        
        if(index+1<v.size()&&v[index+1]==v[index]){
            ans|= get(v,index+2);
        }
        if(index+2<v.size() && v[index]==v[index+1] && v[index+1]==v[index+2]){
            ans|= get(v,index+3);
        }
        if(index+2<v.size() && v[index]==v[index+1]-1 && v[index+1]==v[index+2]-1){
            ans|= get(v,index+3);
        }
        return dp[index] = ans;
    }
    
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return get(nums,0);
    }
};