class Solution {
public:
    int dp[1001][1001][2];
    int get(vector<int>&v,int sign,int currIndex,int latestIndex){
        if(latestIndex==v.size())
            return 0;
        
        if(dp[currIndex][latestIndex][sign]!=-1)
            return dp[currIndex][latestIndex][sign];
        
        if(sign==0 && v[latestIndex]-v[currIndex]>0 || sign==1 && v[latestIndex]-v[currIndex]<0 )
            return dp[currIndex][latestIndex][sign] = max(1+get(v,v[latestIndex]-v[currIndex]<0?0:1,latestIndex,latestIndex+1),get(v,sign,currIndex,latestIndex+1));
        else
            return dp[currIndex][latestIndex][sign] = get(v,sign,currIndex,latestIndex+1);
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        if(nums.size()==2){
            if(nums[0]!=nums[1])
                return 2;
            else
                return 1;
        }

        memset(dp,-1,sizeof dp);
        
        int ans=1;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j])
                    continue;
                ans =  max(ans,2+get(nums,nums[j]-nums[i]<0?0:1,j,j+1));
            }
        }
        return ans;
    }
};

