class Solution {
public:
    int dp[101];
    int r(vector<int>&nums,int i){
        
        if(i>=nums.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        return dp[i] = max(nums[i]+r(nums,i+2),r(nums,i+1));   
    }
    
    int rob(vector<int>& nums) {
        for(int i=0;i<101;i++)dp[i]=-1;
        return r(nums,0);
    }
};